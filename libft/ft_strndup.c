/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:38:42 by bizcru            #+#    #+#             */
/*   Updated: 2024/10/18 16:34:18 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*rtrn;
	char	*i;

	if (ft_strlen(s) < n)
		n = ft_strlen(s);
	rtrn = malloc(n + 1);
	if (rtrn == NULL)
		return (NULL);
	i = rtrn;
	while (n-- > 0)
	{
		*i = *s;
		i++;
		s++;
	}
	*i = 0;
	return (rtrn);
}
