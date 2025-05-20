/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:40:43 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/29 15:48:14 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew(int *data)
{
	t_node	*rtrn;

	rtrn = malloc(sizeof(t_node));
	if (!rtrn)
		return (NULL);
	rtrn->data = *data;
	rtrn->next = NULL;
	rtrn->prev = NULL;
	rtrn->r_len = -1;
	rtrn->rr_len = -1;
	return (rtrn);
}
