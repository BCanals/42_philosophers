/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_pshswp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:18:02 by bcanals-          #+#    #+#             */
/*   Updated: 2024/11/21 21:00:42 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*manage_return_min(char *str)
{
	int	*i;

	free(str);
	i = ft_calloc(sizeof(int), 1);
	*i = INT_MIN;
	return (i);
}

static int	*manage_return(int value)
{
	int	*i;

	i = ft_calloc(sizeof(int), 1);
	*i = value;
	return (i);
}

static void	load_i_sign(int *i, int *sign, char first_ch)
{
	if (first_ch == '-' || first_ch == '+')
		*i = 1;
	if (first_ch == '-')
		*sign = -1;
}

int	*ft_atoi_pshswp(const char *str)
{
	int		rtrn;
	int		temp;
	int		i;
	int		sign;
	char	*int_min;

	int_min = ft_itoa(INT_MIN);
	if (ft_strcmp(str, int_min) == 0)
		return (manage_return_min(int_min));
	free(int_min);
	i = 0;
	sign = 1;
	load_i_sign(&i, &sign, str[i]);
	rtrn = 0;
	temp = 0;
	while (str[i])
	{
		temp = rtrn * 10 + str[i++] - 48;
		if (temp < rtrn)
			return (NULL);
		rtrn = temp;
	}
	rtrn *= sign;
	return (manage_return(rtrn));
}
