/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:14:14 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/05 19:09:55 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_file.h"

void	get_first_line(t_list **line, int fd)
{
	int		oct_lu;
	char	*c;

	c = (char*)malloc(sizeof(char));
	oct_lu = read(fd, c, 1);
	while (oct_lu == SIZE_BUFF && *c != '\n')
	{
		c = (char*)malloc(sizeof(char));
		oct_lu = read(fd, c, 1);
		if (oct_lu)
			ft_list_push_front(line, c);
		param(SIZE_X, oct_lu);
	}
}
