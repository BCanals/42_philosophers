/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <bcanals-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:22:44 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/11 13:38:13 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				retr;
	unsigned int	i;

	i = 0;
	retr = 0;
	while (s1[i] != 0 || s2[i] != 0)
	{
		retr = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (retr != 0)
			return (retr);
		i++;
	}
	return (retr);
}
