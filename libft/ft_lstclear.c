/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:40:22 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/21 19:58:52 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_node **lst)
{
	t_node	*node;
	t_node	*next;

	if (!lst || !*lst)
		return ;
	node = *lst;
	while (node)
	{
		next = node->next;
		ft_lstdelone(node);
		node = next;
	}
	*lst = NULL;
}
