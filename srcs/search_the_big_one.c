/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_the_big_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:50:29 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 15:06:26 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_the_big_one.h"

static	short	init_var(short **line_temp, short **line_work, short *y_max)
{
	short	i;
	short	max;
	char	plein;
	char	vide;

	max = param(SIZE_X, 0);
	*line_temp = (short*)malloc(sizeof(short) * max);
	*line_work = (short*)malloc(sizeof(short) * max);
	plein = param(PLEIN, 0);
	vide = param(VIDE, 0);
	i = 0;
	while (i < max)
	{
		line_temp[0][i] = 0;
		line_work[0][i] = 0;
			i++;
	}
	return (1);
}

short			big_sqr_data(short mode, short value)
{
	static	short	x = 0;
	static	short	y = 0;
	static	short	size = 0;

	if(mode & X)
		return ((mode & SET) ? x = value : x);
	if(mode & Y)
		return ((mode & SET) ? y = value : y);
	if(mode & SIZE)
		return ((mode & SET) ? size = value : size);
	return (0);
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
	else
	{
		if (a < b && a < c)
			return (a);
		if (b < a && b < c)
			return (b);
		else
			return (c);
	}
}

static	void	increm_max(short *line_work, i)
{
	short	x_max;
	short	max;

	max = (big_sqr_data(SIZE, 0))
	x_max = param(SIZE_X, 0);
	while (i < x_max)
	{
		if (line_work[i] > max)
		{
			big_sqr_data(SET | SIZE, line_work[i]);
			big_sqr_data(SET | X, i);
			big_sqr_data(SET | Y, j);
		}
		i++;
	}
}

static	void	increm_num_line(t_bin **tab, short *line_temp, short *line_work, short j)
{
	short			i;
	static	short	nb_var = ((param(SIZE_X, 0) - 1) / ((8 *  sizeof(t_bin)) - 1)) + 1;
	short			k;
	static			t_bin	val = 0;
	short			max;

	i = -1;
	max = (sizeof(t_bin) * 8) - BIT_LESS;
	while (++i < nb_var)
	{
		k = -1;
		if (j)
			val = (tab[j][i] & tab[j - 1][i] & tab[j][i] >> 1 & tab[j - 1][i] >> 1);
		while (++k < max)
		{
			if (j && (val & 1 << k))
				line_work[i * max + k] = 1 + min_val(line_work, line_temp, i * max + k);
			else if (tab[j][i] & 1 << k)
				line_work[i * max + k] = 1;
			else
				line_work[i * max + k] = 0
		}
		increm_max(line_work, i);
	}
}

short			search_the_big_one(t_bin **tab)
{
	short	*line_temp;
	short	*line_work;
	short	y_max;
	short	j;

	j = 0;
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
