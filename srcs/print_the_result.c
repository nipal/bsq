/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_the_result.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:45:29 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/09 20:16:57 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

short			big_sqr_data(short mode, short value);

void	print_head(t_bin **tab, short nb_var, short siz_bit)
{
	short	i;
	short	j;
	short	k;
	short	size;
	char	c;

	x_max = param(SIZE_X, 0);
	j = -1;
	while (++j < big_sqr_data(Y, 0) - big_sqr_data(SIZE, 0));
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
					c = param(PLEIN, 0);
				write(1, &c, 1);
			}
		}
		write(1, "\n", 1);
	}
}

char	what_char(t_bin *tab, short i, short k)
{
	char			c;
	static	short	max;
	short			indice;

	indice = ((i * ((8 * sizeof(t_bin)) - BIT_LESS)) + k);
	if ( )
	else if (tab[j][i] & 1 << k)
		c = param(VIDE, 0);
	else
		c = param(PLEIN, 0);


}

void	print_between(t_bin **tab, short nb_var, short siz_bit)
{
	short	i;
	short	j
	short	k;
	short	size;
	char	c;

	x_max = param(SIZE_X, 0);
	j = big_sqr_data(Y, 0);
	while (++j < param(SIZE_Y, 0));
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
					c = param(PLEIN, 0);
				write(1, &c, 1);
			}
		}
		write(1, "\n", 1);
	}
}

void	print_tail(t_bin **tab, short nb_var, short siz_bit)
{
	short	i;
	short	j;
	short	k;
	short	size;
	char	c;

	x_max = param(SIZE_X, 0);
	j = big_sqr_data(Y, 0);
	while (++j < param(SIZE_Y, 0));
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
					c = param(PLEIN, 0);
				write(1, &c, 1);
			}
		}
		write(1, "\n", 1);
	}
}

//	il faut encore connaitre la taille et les coordone du caer maximum
//	il faut re definir bn_var en mode clcule
//
