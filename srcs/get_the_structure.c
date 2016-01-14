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

int		fill_the_char(char c, t_bin *line_b, int init)
{
	static	int		i = 0;
	int				size_b;

	size_b = sizeof(t_bin) * 8;
	if (init)
		i = 0;
	if (c == param(VIDE, 0))
		line_b[i / size_b] += 1 << i % size_b;
	else if (c != param(OBSTACLE, 0))
		return (0);
	i++;
	return (1);
}

int		fill_line_bin(t_bin *line_bin, char *line_char, int x_max, int i_c)
{
	fill_the_char(0, 0, 1);
	while (i_c < x_max + 1)
	{
		if(!fill_the_char(line_char[i_c], line_bin, 0))
			return (0);
		i_c++;
	}
	return (1);
}

int		get_the_structure(t_bin **tab, int fd, int x_max, int y_max)
{
	int		j;
	int		oct_lu;
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
	free(line);
	return (1);
}
