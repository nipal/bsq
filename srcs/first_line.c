/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:14:14 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 18:55:19 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_line.h"

void	get_first_line(t_list **line, int fd)
{
	int		oct_lu;
	char	*c;
	int line_bug = 0;

	line_bug = -1;
	*line = 0;
	c = (char*)malloc(sizeof(char) * 2);
	c[1] = 0;
	oct_lu = read(fd, c, 1);
	if (oct_lu)
		ft_list_push_back(line, c);
	while (oct_lu == 1 && *c != '\n')
	{
		c = (char*)malloc(sizeof(char));
		oct_lu = read(fd, c, 1);
		if (oct_lu && *c != '\n')
			ft_list_push_back(line, c);
		param(SIZE_X, oct_lu);
	}
}
