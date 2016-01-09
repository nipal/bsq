/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copie_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/07 01:14:28 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_file.h"

short	copie_first_line(t_bin **tab, t_list *first_line, short i, short coef)
{
	short	nb_var;
	t_bin	max;
	
	nb_var = ((param(SIZE_X, 0) - 1) / ((8 *  sizeof(t_bin)) - 1)) + 1;
	tab[0] = malloc_line(nb_var);
	max = 1 << (8 * sizeof(t_bin) - 1);
	fill_the_char(0, 0, 0, 1);
	while (first_line)
	{
		if(fill_the_char(*(first_line->data), tab[0], max, 0) == -1)
			return (-1);
		first_line = first_line->next;
	}
	ft_list_clear(&first_line);
}
