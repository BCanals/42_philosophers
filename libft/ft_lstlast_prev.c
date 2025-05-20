/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 02:48:49 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/22 19:43:59 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstlast_prev(t_node *lst)
{
	t_node	*not_last;

	not_last = lst;
	while (not_last->next->next)
		not_last = not_last->next;
	return (not_last);
}
