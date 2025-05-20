/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:47:43 by bizcru            #+#    #+#             */
/*   Updated: 2024/10/18 16:33:14 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s2;
	unsigned char	c2;

	s2 = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (*s2)
	{
		if (*s2 == c2)
			return ((char *)(s2));
		s2++;
	}
	if (c2 == 0)
		return ((char *)(s2));
	return (NULL);
}
