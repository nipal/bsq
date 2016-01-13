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
	else if (c != param(OBSTACLE, 0))
		return (0);
	if (coef < max)
		coef = coef << 1;
	else
	{
		if (i_b < (((param(SIZE_X, 0) - 1) / max) + 1))
			line_b[i_b] += ((line_b[i_b + 1]) & 1) << max;
		i_b++;
		coef = 1;
	}
	return (1);
}

short	fill_line_bin(t_bin *line_bin, char *line_char, short x_max, short i_c)
{
	static	t_bin	max = 1 << ((8 * sizeof(t_bin)) - 1);

	fill_the_char(0, 0, 0, 1);
	while (i_c < x_max + 1)
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

	j = 1;
	line = (char*)malloc(sizeof(char) * (x_max + 1));
	if (!line)
		return (0);
	while (j < (y_max))
	{
		oct_lu = read(fd, line, x_max + 1);
		if (oct_lu != x_max + 1)
			return (0);
		if(fill_line_bin(tab[j], line, x_max, 0))
			return (0);
		j++;
	}
	if (read(fd, line, 1))
		return (0);
	free(line);
	return (1);
}
