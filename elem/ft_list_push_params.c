/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 22:17:31 by fjanoty           #+#    #+#             */
/*   Updated: 2015/12/17 12:59:51 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*begin_list;
	t_list	*elem;
	int		i;

	i = 0;
	begin_list = NULL;
	while (i < ac)
	{
		elem = ft_create_elem(*(av + i));
		elem->next = begin_list;
		begin_list = elem;
		i++;
	}
	return (begin_list);
}
