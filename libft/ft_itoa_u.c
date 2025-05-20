/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:18:02 by bcanals-          #+#    #+#             */
/*   Updated: 2024/10/18 16:24:01 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_digits(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void	fill(char *rtrn, unsigned int n, int size)
{
	rtrn[size] = 0;
	size--;
	if (n == 0)
		rtrn[0] = 48;
	while (n > 0)
	{
		rtrn[size] = (n % 10) + 48;
		n /= 10;
		size--;
	}
}

char	*ft_itoa_u(unsigned int n)
{
	char	*rtrn;
	int		size;

	size = get_num_digits(n);
	rtrn = malloc(size + 1);
	if (rtrn == NULL)
		return (NULL);
	fill(rtrn, n, size);
	return (rtrn);
}
