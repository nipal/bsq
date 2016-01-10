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
#include <stdio.h>

short	copie_first_line(t_bin **tab, t_list *first_line)
{
	short	nb_var;
	t_bin	max;
	int	bug = 0;
	int	boucle = 0;
	
dprintf(1, "copie firt line %d	est ok\n", ++bug);
	nb_var = ((param(SIZE_X, 0) - 1) / ((8 *  sizeof(t_bin)) - 1)) + 1;
dprintf(1, "copie firt line %d	est ok\n", ++bug);
	tab[0] = malloc_line(nb_var);
dprintf(1, "copie firt line %d	est ok\n", ++bug);
	max = 1 << (8 * sizeof(t_bin) - 1);
dprintf(1, "copie firt line %d	est ok\n", ++bug);
	fill_the_char(0, 0, 0, 1);
dprintf(1, "copie firt line %d	est ok\n", ++bug);
	while (first_line && dprintf(1, "haha\n"))
	{
		dprintf(1, "jojo le toro\n");
dprintf(1, "copie firt line %d	boucle1 %d	est ok pour %c\n", bug, ++boucle, (*(char*)(first_line->data)));
		if(fill_the_char((*(char*)(first_line->data)), tab[0], max, 0) == -1)
			return (0);
dprintf(1, "copie firt line %d	boucle2 %d	est ok\n", bug, boucle);
		first_line = first_line->next;
dprintf(1, "fin de bouccle\n");
	}
dprintf(1, "copie firt line %d	est ok\n", ++bug);
	ft_list_clear(&first_line);
dprintf(1, "copie firt line %d	est ok\n", ++bug);
	return (1);
}
