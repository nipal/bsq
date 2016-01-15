/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:28:02 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:40:42 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_file.h"

t_bin	*malloc_line(int size)
{
	t_bin	*new_line;
	int		i;

	i = 0;
	new_line = (t_bin*)malloc(size * sizeof(t_bin));
	while (i < size)
	{
		new_line[i] = 0;
		i++;
	}
	return (new_line);
}

int		init_tab_bin(t_bin **tab)
{
	int		j;
	int		y_max;
	int		nb_var;
	int		i;

	j = 1;
	y_max = param(SIZE_Y, 0);
	nb_var = ((param(SIZE_X, 0) - 1) / ((8 * sizeof(t_bin) - 1) - 1)) + 1;
	while (j < y_max)
	{
		tab[j] = malloc_line(nb_var);
		if (!(tab + j))
			return (0);
		i = 0;
		while (i < nb_var)
		{
			tab[j][i] = 0;
			i++;
		}
		j++;
	}
	return (1);
}

void	free_tab(t_bin **tab)
{
	int		j;
	int		y_max;

	j = 0;
	y_max = param(SIZE_Y, 0);
	while (j < y_max)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

int		ft_print_file(char *name)
{
	int		fd;
	t_list	*line;
	t_bin	**tab_bsq;

	if (name)
		fd = open(name, O_RDONLY, S_IREAD);
	else
		fd = 0;
	if (init_param(fd) != 1)
		return (-1);
	get_first_line(&line, fd);
	tab_bsq = (t_bin**)malloc(sizeof(t_bin*) * param(SIZE_Y, 0));
	if (!copie_first_line(tab_bsq, line))
		return (-1);
	if (!init_tab_bin(tab_bsq))
		return (-2);
	if (!get_the_structure(tab_bsq, fd, param(SIZE_X, 0), param(SIZE_Y, 0)))
		return (-1);
	close(fd);
	if (solve(tab_bsq, param(SIZE_Y, 0), param(SIZE_X, 0)))
		return (-2);
	print_the_result(tab_bsq);
	free_tab(tab_bsq);
	return (0);
}
