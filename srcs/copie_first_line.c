/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copie_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 20:01:54 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "copie_first_line.h"

int		copie_first_line(t_bin **tab, t_list *first_line)
{
	int		nb_var;
	
	nb_var = ((param(SIZE_X, 0) - 1) / ((8 *  sizeof(t_bin)))) + 1;
	tab[0] = malloc_line(nb_var);
	fill_the_char(0, 0, 1);
	while (first_line)
	{
		if(fill_the_char((*(char*)(first_line->data)), tab[0], 0) == -1)
			return (0);
		first_line = first_line->next;
	}
	ft_list_clear(&first_line);
	return (1);
}
