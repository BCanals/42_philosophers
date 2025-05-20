/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:59:46 by bcanals-          #+#    #+#             */
/*   Updated: 2024/10/18 16:32:25 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_base_size(char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

static int	check_arguments(char *base)
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

static int	ft_putnbr_base_easy(int nbr, char *base, int size, int *count)
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

static int	manage_int_min(int size, char *base, int *count)
{
	char		c;
	int			nbr;

	write(1, "-", 1);
	(*count)++;
	nbr = 2147483648 / size;
	ft_putnbr_base_easy(nbr, base, size, count);
	c = base[2147483648 % size];
	write(1, &c, 1);
	return (++*count);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	char	c;
	int		count;

	count = 0;
	if (check_arguments(base) == 0)
		return (0);
	size = get_base_size(base);
	if (nbr == -2147483648)
		return (manage_int_min(size, base, &count));
	else if (nbr == 0)
		return (write(1, &base[0], 1));
	else if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
	}
	if (nbr >= size)
		ft_putnbr_base_easy(nbr / size, base, size, &count);
	c = base[nbr % size];
	write(1, &c, 1);
	return (++count);
}
