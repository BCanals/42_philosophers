/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:43:53 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/11 13:40:12 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	len;
	size_t	lit_len;

	i = 0;
	if (little[0] == 0)
		return ((char *)(big));
	lit_len = ft_strlen(little);
	len = ft_strlen(big) - lit_len;
	while (i <= len)
	{
		if (ft_strncmp(big, little, lit_len) == 0)
			return ((char *)(big));
		big++;
		i++;
	}
	return (NULL);
}
