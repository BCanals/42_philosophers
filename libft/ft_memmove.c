/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:50:13 by bizcru            #+#    #+#             */
/*   Updated: 2024/12/04 17:35:12 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
		return (NULL);
	if (dest > src)
		ft_memrcpy(dest, src, n);
	else if (src > dest)
		ft_memcpy(dest, src, n);
	return (dest);
}
