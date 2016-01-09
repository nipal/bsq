/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 21:07:28 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/05 13:59:31 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void*))
{
	int		i;
	int		size;
	t_list	*elem;

	i = 0;
	size = ft_list_size(begin_list);
	elem = begin_list;
	while (i < size)
	{
		(*f)(elem->data);
		elem = elem->next;
		i++;
	}
}
