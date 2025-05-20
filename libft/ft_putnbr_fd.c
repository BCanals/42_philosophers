/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:34:37 by bizcru            #+#    #+#             */
/*   Updated: 2024/10/18 16:32:54 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_putnbr(unsigned int n, int fd)
{
	char	nbr;

	if (n > 9)
		my_putnbr(n / 10, fd);
	nbr = n % 10 + 48;
	write(fd, &nbr, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		my_putnbr((unsigned int) ~(n - 1), fd);
	}
	else
		my_putnbr((unsigned int)n, fd);
}
