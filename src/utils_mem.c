/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:13:14 by bcanals-          #+#    #+#             */
/*   Updated: 2026/06/14 19:13:34 by becanals         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		*ptr = c;
		i++;
		ptr++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rtrn;

	rtrn = malloc(nmemb * size);
	if (rtrn == NULL)
		return (NULL);
	ft_memset(rtrn, 0, nmemb * size);
	return (rtrn);
}

void	cleanup(t_table *table)
{
	int	i;

	free(table->id);
	free(table->ini_t);
	i = -1;
	while (table->philos[++i])
	{
		free(table->philos[i]->my_time);
		free(table->philos[i]);
	}
	free(table->philos);
	free(table);
}

