/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverese.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 21:07:28 by fjanoty           #+#    #+#             */
/*   Updated: 2015/12/16 19:34:06 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next;
	t_list	*current;
	t_list	*prev;

	prev = 0;
	current = *begin_list;
	if (current && current->next)
	{
		prev = current;
		next = (current->next)->next;
		current = current->next;
		prev->next = 0;
	}
	else
		return ;
	while (current)
	{
		current->next = prev;
		prev = current;
		current = next;
		if (next)
			next = next->next;
	}
	if (prev)
		*begin_list = prev;
}
