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

static	char	what_char(t_bin *tab, int i, int j, int size_b)
{
	int		sqr_size;
	int		sqr_x;
	int		sqr_y;

	sqr_y = big_sqr_data(Y, 0);
	sqr_x = big_sqr_data(X, 0);
	sqr_size = big_sqr_data(SIZE, 0);
	size_b = sizeof(t_bin) * 8;

	if (i > (sqr_x - sqr_size) && i <= sqr_x
	&& j > (sqr_y - sqr_size) && j <= sqr_y )
		return (param(PLEIN, 0));
	if (tab[i / size_b] & 1 << (i % size_b))
		return (param(VIDE, 0));
	return (param(OBSTACLE, 0));
}

static	void	print_between(t_bin **tab, int nb_var, int siz_bit)
{
	int		i;
	int		j;
	int		y_max;
	char	c;

	y_max = param(SIZE_Y, 0);
	j = -1;
	while (++j < y_max)
	{
		i = -1;
		while (++i < nb_var)
		{
			c = what_char(tab[j], i, j, siz_bit);
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}

void	print_the_result(t_bin **tab)
{
	int		siz_bit;

	siz_bit =  ((sizeof(t_bin) * 8));
	print_between(tab, param(SIZE_X, 0), siz_bit);
}
