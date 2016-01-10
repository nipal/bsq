/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_structure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:02:30 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 20:01:52 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_the_structure.h"
#include <stdio.h>

short	fill_the_char(char c, t_bin *line_b, t_bin max, short init)
{
	static	t_bin	coef = 1;
	static	short	i_b = 0;

	if (init)
	{
		coef = 1;
		i_b = 0;
	}
	if (c == param(VIDE, 0))
		line_b[i_b] += coef;
	else if (c != param(PLEIN, 0))
		return (0);
	if (coef < max)
		coef = coef << 1;
	else
	{
		if (i_b < ((param(SIZE_X, 0) - 1) / max))
			line_b[i_b] += (line_b[i_b + 1] & 1) << max;
		i_b++;
		coef = 1;
	}
	return (1);
}

short	fill_line_bin(t_bin *line_bin, char *line_char, short x_max, short i_c)
{
	t_bin			coef;
	static	t_bin	max = 1 << ((8 * sizeof(t_bin)) - 1);

	coef = 1;
	while (i_c < x_max)
	{
		if(!fill_the_char(line_char[i_c], line_bin, max, 0))
			return (0);
		i_c++;
	}
	return (1);
}

short	get_the_structure(t_bin **tab, int fd, short x_max, short y_max)
{
	short	j;
	short	oct_lu;
	char	*line;
int line_bug = 0;
int boucle_bug = 0;

	j = 1;
//dprintf(1, "get the structure line %d et ymax: %d  %d\n", j, y_max, ++line_bug);
	line = (char*)malloc(sizeof(char) * (x_max + 1));
	if (!line)
	{
dprintf(1, "Mauvais malloc\n");
		return (0);
	}
//dprintf(1, "get the structure line ok pour %d\n", ++line_bug);
	while (j < (y_max - 3))
	{
//dprintf(1, "get the structure j: %d boucle %d\n", j, ++boucle_bug);
		oct_lu = read(fd, line, x_max + 1);
		if (oct_lu != x_max + 1)
		{
dprintf(1, "mauvais oct_lu: %d pour fd: %d x_max: %d\n", oct_lu, fd, x_max);
			return (0);
		}
		if(fill_line_bin(tab[j], line, x_max, 0) == -1)
		{
dprintf(1, "mauvais carracter\n");
			return (0);
		}
		j++;
	}
	free(line);
	return (1);
}
