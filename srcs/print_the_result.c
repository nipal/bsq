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

static	void	print_head(t_bin **tab, short x_max, short nb_var, short siz_bit)
{
	short	i;
	short	j;
	short	k;
	char	c;

	x_max = param(SIZE_X, 0);
	j = -1;
	while (++j < big_sqr_data(Y, 0) - big_sqr_data(SIZE, 0))
	{
		i = -1;
		while (++i < nb_var)
		{
			k = -1;
			while (++k < siz_bit && i * siz_bit + k < param(SIZE_X, 0))
			{
				if (tab[j][i] & 1 << k)
					c = param(VIDE, 0);
				else
					c = param(OBSTACLE, 0);
				write(1, &c, 1);
			}
		}
		write(1, "\n", 1);
	}
}

static	char	what_char(t_bin *tab, short i, short k)
{
	char			c;
	short			indice;
	short	max;
	short	sqr_x;
	short	sqr_size;

	max = param(SIZE_X, 0);
	sqr_x = big_sqr_data(X, 0);
	sqr_size = big_sqr_data(SIZE, 0);

	indice = ((i * ((8 * sizeof(t_bin)) - 1)) + k);
	if (indice >= sqr_x - sqr_size && indice <= sqr_x)
		c = param(PLEIN, 0);
	else if (tab[i] & 1 << k)
		c = param(VIDE, 0);
	else
		c = param(OBSTACLE, 0);
	return (c);
}

static	void	print_between(t_bin **tab, short x_max, short nb_var, short siz_bit)
{
	short	i;
	short	j;
	short	k;
	char	c;

	x_max = param(SIZE_X, 0);
	j = big_sqr_data(Y, 0);
	while (++j < param(SIZE_Y, 0))
	{
		i = -1;
		while (++i < nb_var)
		{
			k = -1;
			while (++k < siz_bit && i * siz_bit + k < param(SIZE_X, 0))
			{
				c = what_char(tab[j], i, k);
				write(1, &c, 1);
			}
		}
		write(1, "\n", 1);
	}
}

static	void	print_tail(t_bin **tab, short x_max ,short nb_var, short siz_bit)
{
	short	i;
	short	j;
	short	k;
	char	c;

	x_max = param(SIZE_X, 0);
	j = big_sqr_data(Y, 0);
	while (++j < param(SIZE_Y, 0))
	{
		i = -1;
		while (++i < nb_var)
		{
			k = -1;
			while (++k < siz_bit && i * siz_bit + k < param(SIZE_X, 0))
			{
				if (tab[j][i] & 1 << k)
					c = param(VIDE, 0);
				else
					c = param(OBSTACLE, 0);
				write(1, &c, 1);
			}
		}
		write(1, "\n", 1);
	}
}

void	print_the_result(t_bin **tab)
{
	short	nb_var;
	short	siz_bit;

	siz_bit =  ((sizeof(t_bin) * 8) - 1);
	nb_var = ((param(SIZE_X, 0) - 1) / siz_bit) + 1;
	print_head(tab, nb_var, 0, siz_bit);
	print_between(tab, 0, nb_var, siz_bit);
	print_tail(tab, 0, nb_var, siz_bit);
}
