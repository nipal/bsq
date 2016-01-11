/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_the_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:45:29 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 17:41:03 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_the_result.h"
#include <stdio.h>

void	print_all();
void	print_all_sqr()
{
dprintf(1, "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
dprintf(1, "sqr-x	%d\n", big_sqr_data(X, 0));
dprintf(1, "sqr-y	%d\n", big_sqr_data(Y, 0));
dprintf(1, "size	%d\n", big_sqr_data(SIZE, 0));
dprintf(1, "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
}
static	char	what_char(t_bin *tab, short i, short k, short j)
{
	short	indice;
	short	max;
	short	sqr_size;
	short	sqr_x;
	short	sqr_y;

	max = param(SIZE_X, 0);
	sqr_x = big_sqr_data(X, 0);
	sqr_y = big_sqr_data(Y, 0);
	sqr_size = big_sqr_data(SIZE, 0);

	indice = ((i * ((8 * sizeof(t_bin)) - 1)) + k);
	if (indice > sqr_x - sqr_size && indice <= sqr_x
	&& j > sqr_y - sqr_size && j <= sqr_y )
		return (param(PLEIN, 0));
	else if (tab[i] & 1 << k)
		return (param(VIDE, 0));
	else
		return (param(OBSTACLE, 0));
}

static	void	print_between(t_bin **tab, short nb_var, short siz_bit)
{
	short	i;
	short	j;
	short	k;
	short	y_max;
	char	c;

	y_max = param(SIZE_Y, 0);
	j = -1;
dprintf(1 , "i: %d v: %d\n",(i * siz_bit + k), (param(SIZE_X, 0)));
	while (++j < y_max)
	{
		i = -1;
		dprintf(1, "line %d	", j);
		while (++i < nb_var)
		{
			k = -1;
			while (++k < siz_bit && i * siz_bit + k < param(SIZE_X, 0))
			{
//dprintf(1 , " |%d|",(i * siz_bit + k));
				c = what_char(tab[j], i, k, j);
				write(1, &c, 1);
			}
		}
		write(1, "\n", 1);
	}
}

void	recap()
{
	dprintf(1, "larhgeur %d\n", param(SIZE_X, 0));
}

void	print_the_result(t_bin **tab)
{
	short	nb_var;
	short	siz_bit;

print_all_sqr();
	siz_bit =  ((sizeof(t_bin) * 8));
	nb_var = ((param(SIZE_X, 0) - 1) / siz_bit) + 1;
print_all();
	print_between(tab, nb_var, siz_bit);
}
