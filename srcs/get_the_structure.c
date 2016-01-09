/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:02:30 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/09 20:16:51 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_the_structure.c"

short	fill_the_char(char c, t_bin *line_b, t_bin max, short init)
{
	static	t_bin	coef = 1;
	static	short	i_b = 0;
	static	short	max = ((8 * sizeof(t_bin)) - BIT_LESS);

	if (init)
	{
		coef = 1;
		i_b = 0;
	}
	if (c == param(VIDE, 0))
		line_b[i_b] += coef;
	else if (c != param(PLEIN, 0))
		return (-1);
	if (coef < max)
		coef = coef << 1;
	else
	{
		if (i_b < ((param(SIZE_X, 0) - 1) / max))
			line_b[i_b] += (line_b[i_b + 1] & 1) << max;
		i_b++;
		coef = 1;
	}
	return (0);
}

short	fill_line_bin(t_bin *line_bin, char *line_char, short x_max, short i_c)
{
	t_bin			coef;
	static	t_bin	max = 1 << ((8 * sizeof(t_bin)) - BIT_LESS);

	coef = 1;
	while (i_c < x_max)
	{
		if(fill_the_char(line_char[i_c], line_bin, max, 0) == -1)
			return (-1);
		i_c++;
	}
	return (-0);
}

short	get_the_structure(t_bin **tab, int fd, short x_max, short y_max)
{
	short	j;
	short	nb_var;
	short	oct_lu;
	short	coef;
	char	*line;

	j = 1;
	nb_var = ((x_max - 1) / ((8 *  sizeof(t_bin)) - 1)) + 1;
	line = (char*)malloc(sizeof(char) * (x_max + 1));
	if (!line)
		return (-2);
	while (j < y_max)
	{
		i = 0;
		if((tab[j] = (t_bin*)malloc(sizeof(t_bin) * nb_var)) == 0)
			return (-2);
		oct_lu = read(fd, line, x_max + 1);
		if (oct_lu != x_max)
			return (-1);
		if(fill_line_bin(tab[j], line, x_max, 0) == -1)
			return (-1);
		j++;
	}
	free(line);
	return (0);
}
