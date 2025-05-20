/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:22:49 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/11 16:16:44 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*ft_next(char *buffer, char *line)
{
	char	*new_buffer;
	size_t	buf_len;
	size_t	line_len;

	line_len = ft_strlen(line);
	buf_len = ft_strlen(buffer) - line_len;
	new_buffer = ft_calloc(1, buf_len + 1);
	if (!new_buffer)
		return (ft_free(&line), ft_free(&buffer));
	new_buffer = ft_memcpy(new_buffer, buffer + line_len, buf_len);
	ft_free(&buffer);
	return (new_buffer);
}

static char	*ft_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(1, i + 1);
	if (!line)
		return (ft_free(&line));
	ft_memcpy(line, buffer, i);
	return (line);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*reading;
	int		read_bytes;

	while (!ft_strchr(buffer, '\n'))
	{
		reading = ft_calloc(1, BUFFER_SIZE + 1);
		if (!reading)
			return (NULL);
		read_bytes = read(fd, reading, BUFFER_SIZE);
		if (read_bytes < 0)
			return (ft_free(&reading), ft_free(&buffer));
		else if (read_bytes == 0)
		{
			ft_free(&reading);
			return (buffer);
		}
		buffer = ft_strjoinf(buffer, reading);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer[fd])
			ft_free(&buffer[fd]);
		return (NULL);
	}
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	if (!buffer[fd])
		return (ft_free(&buffer[fd]));
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	if (!*buffer[fd])
		return (ft_free(&buffer[fd]));
	line = ft_line(buffer[fd]);
	if (!line)
		return (ft_free(&buffer[fd]), ft_free(&line));
	buffer[fd] = ft_next(buffer[fd], line);
	if (!buffer[fd])
		return (ft_free(&buffer[fd]));
	return (line);
}
