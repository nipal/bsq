/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_the_big_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:50:29 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 17:08:48 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_the_big_one.h"

static	short	init_var(short **line_temp, short **line_work, short *y_max)
{
	short	i;
	short	max;

	max = param(SIZE_X, 0);
	*line_temp = (short*)malloc(sizeof(short) * max);
	*line_work = (short*)malloc(sizeof(short) * max);
	*y_max = max;
	i = 0;
	while (i < max)
	{
		line_temp[0][i] = 0;
		line_work[0][i] = 0;
			i++;
	}
	return (1);
}

static	short 	min_val(short *line_work, short *line_temp, short i)
{
	short	a;
	short	b;
	short	c;

	if (i == 0)
		return (0);
	a = line_work[i - 1];
	b = line_temp[i];
	c = line_temp[i - 1];
	if (a < b && a < c)
		return (a);
	if (b < a && b < c)
		return (b);
	else
		return (c);
}


t_bin			def_val(t_bin **tab, short j, short i, short max)
{
	t_bin	val;
	t_bin	a;
	t_bin	b;
	t_bin	c;
	t_bin	d;


	a = tab[j][i];
	b = tab[j - 1][i];
	if (i)
	{
		c = (tab[j][i] << 1) | ((tab[j][i - 1] & 1 << max) >> max);
		d = (tab[j - 1][i] << 1) | ((tab[j - 1][i - 1] & 1 << max) >> max);
	}
	else
	{
		c = tab[j][i] << 1;
		d = tab[j - 1][i] << 1;
	}
	val = a & b & c & d;
	return (val);
}

static	void	increm_num_line(t_bin **tab, short *line_temp, short *line_work
		, short j)
{
	short	i;
	short	nb_var;
	short	k;
	t_bin	val;
	short	max;

	nb_var = ((param(SIZE_X, 0) - 1) / ((8 *  sizeof(t_bin)) - 1)) + 1;
	i = -1;
	max = (sizeof(t_bin) * 8) - 1;
	while (++i < nb_var)
	{
		k = -1;
		if (j)
			val = def_val(tab, j, i, max);
		while (++k < max)
		{
			if (j && (val & 1 << k))
				line_work[i * max + k] = 1 + min_val(line_work, line_temp, i * max + k);
			else if (tab[j][i] & 1 << k)
				line_work[i * max + k] = 1;
			else
				line_work[i * max + k] = 0;
		}
	}
		increm_max(line_work, j);
}

short			search_the_big_one(t_bin **tab)
{
	short	*line_temp;
	short	*line_work;
	short	y_max;
	short	j;

	j = 0;
	init_big_sqr();
	init_var(&line_temp, &line_work, &y_max);
	if (!line_temp || !line_work)
		return (-2);
	while (j < y_max)
	{
		if (j % 2 == 0)
			increm_num_line(tab, line_temp, line_work, j);
		else
			increm_num_line(tab, line_work, line_temp, j);
		j++;
	}
	return (0);
}
