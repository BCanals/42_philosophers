/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bizcru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 04:17:34 by bizcru            #+#    #+#             */
/*   Updated: 2024/11/27 17:25:07 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstmap(t_node *lst, int (*f)(int))
{
	t_node	*rtrn;
	t_node	*last;
	t_node	*my_list;

	my_list = lst;
	if (!my_list || !f)
		return (NULL);
	rtrn = NULL;
	while (my_list)
	{
		last = malloc(sizeof(t_node));
		if (!last)
		{
			ft_lstclear(&rtrn);
			return (NULL);
		}
		last->data = f(my_list->data);
		last->next = NULL;
		last->prev = my_list;
		ft_lstadd_back(&rtrn, last);
		my_list = my_list->next;
	}
	return (rtrn);
}
