/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:59:46 by bcanals-          #+#    #+#             */
/*   Updated: 2024/11/21 13:49:58 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_base_size(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

int	check_arguments(char *base)
{
	int	i;
	int	j;

	if (get_base_size(base) < 2)
		return (0);
	i = 0;
	while (base[i + 1] != 0)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (base[i] == '+' || base[i] == '-' || base[i] == ' '
		|| (base[i] >= 9 && base[i] <= 13))
		return (0);
	return (1);
}

int	ft_putnbr_base_easy(size_t nbr, char *base, unsigned int size, int *count)
{
	char		c;

	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return (++*count);
	}
	else if (nbr >= size)
		ft_putnbr_base_easy(nbr / size, base, size, count);
	c = base[nbr % size];
	write(1, &c, 1);
	return (++*count);
}

int	ft_putnbr_base_u(size_t nbr, char *base)
{
	unsigned int	size;
	char			c;
	int				count;

	count = 0;
	if (check_arguments(base) == 0)
		return (0);
	size = get_base_size(base);
	if (nbr == 0)
		return (write(1, &base[0], 1));
	if (nbr >= size)
		ft_putnbr_base_easy(nbr / size, base, size, &count);
	c = base[nbr % size];
	write(1, &c, 1);
	return (++count);
}
/*
int main ()
{
	char c[] = "+123456789abcdef";
	ft_putnbr_base(42, c);	
}*/
