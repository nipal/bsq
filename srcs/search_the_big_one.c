/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_the_big_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:50:29 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:34:38 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_the_big_one.h"

static	int		init_var2(int **line_temp, int **line_work, int *size_bin)
{
	int		i;
	int		max;

	*size_bin = ((8 * sizeof(t_bin)));
	init_big_sqr();
	max = param(SIZE_X, 0);
	*line_temp = (int*)malloc(sizeof(int) * max);
	*line_work = (int*)malloc(sizeof(int) * max);
	i = 0;
	while (i < max)
	{
		line_temp[0][i] = 0;
		line_work[0][i] = 0;
		i++;
	}
	return (1);
}

static	int		min_val(int *line_work, int *line_temp, int i, int j)
{
	int	a;
	int	b;
	int	c;

	if (i == 0 || j == 0)
		return (0);
	a = line_work[i - 1];
	b = line_temp[i];
	c = line_temp[i - 1];
	a = (a > b) ? b : a;
	a = (a > c) ? c : a;
	return (a);
}

static	void	swap_line(int **str1, int **str2)
{
	int		*str_swp;

	str_swp = *str1;
	*str1 = *str2;
	*str2 = str_swp;
}

void			free_mem(int *mem1, int *mem2)
{
	free(mem1);
	free(mem2);
}

int				solve(t_bin **tab, int y_max, int x_max)
{
	int		*line_temp;
	int		*line_work;
	int		j;
	int		i;
	int		size_bin;

	j = -1;
	init_var2(&line_temp, &line_work, &size_bin);
	if (!line_temp || !line_work)
		return (-2);
	while (++j < y_max)
	{
		i = -1;
		while (++i < x_max)
		{
			if ((tab[j][i / (size_bin)] & (1 << (i % size_bin))))
				line_work[i] = 1 + min_val(line_work, line_temp, i, j);
			else
				line_work[i] = 0;
			increm_max(line_work, j, i);
		}
		swap_line(&line_work, &line_temp);
	}
	return (0);
}
