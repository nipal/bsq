/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 21:07:28 by fjanoty           #+#    #+#             */
/*   Updated: 2015/12/15 20:48:07 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, t_list *insert, int (*cmp)())
{
	t_list	*elem;
	t_list	*prev;

	elem = *begin_list;
	prev = 0;
	while (elem && (*cmp)(insert->data, elem->data) > 0)
	{
		prev = elem;
		elem = elem->next;
	}
	if (prev)
		prev->next = insert;
	else
		*begin_list = insert;
	insert->next = elem;
}

void	ft_sorted_list_merge(t_list **bgl1, t_list *bgl2, int (*cmp)())
{
	t_list	*tmp;

	while (bgl2)
	{
		tmp = bgl2->next;
		ft_sorted_list_insert(bgl1, bgl2, cmp);
		bgl2 = tmp;
	}
}
