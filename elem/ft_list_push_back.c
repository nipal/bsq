/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 21:07:28 by fjanoty           #+#    #+#             */
/*   Updated: 2015/12/13 21:37:17 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*list;
	t_list	*elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	list = *begin_list;
	elem->data = data;
	elem->next = 0;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = elem;
	}
	else
		*begin_list = elem;
}
