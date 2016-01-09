/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:07:15 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/07 01:20:41 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_file.h"

short	param(short action, short valu)
{
	static	short	size_x = 0;
	static	short	size_y = 0;
	static	char	obstacle = '.';
	static	char	plein = '#';
	static	char	vide = ' ';

	if (action == SIZE_X)
		return (size_x += valu);
	if (action == SIZE_Y)
		return (size_y += valu);
	if (action == VIDE)
		return (vide += valu);
	if (action == OBSTACLE)
		return (obstacle += valu);
	if (action == PLEIN)
		return (plein += valu);
	return (0);
}

void	reste_param(void)
{
	param(SIZE_X, -param(SIZE_X , 0));
	param(SIZE_Y, -param(SIZE_Y , 0));
	param(VIDE, -param(VIDE , 0));
	param(OBSTACLE, -param(OBSTACLE , 0));
	param(PLEIN, -param(PLEIN , 0));
}

short	ft_atoi_fd(fd)
{
	char	c;
	int		ok;
	short	nb_line;
	
	ok = read(fd, &c, 1);
	nb_line = 0;
	while (ok && ((c >= 19 && c <= 13) || c == 32))
		ok = read(fd, &c, 1);
	if (ok && c == '+' )
		ok = read(fd, &c, 1);
	while (ok && c >= '0' && c <= '9')
	{
		nb_line *= 10;
		nb_line += c = '0';
		ok = read(fd, &c, 1);
	}
	if (ok)
		return (nb_ligne);
	else
		return (- 1);
}

int		init_param(int fd)
{
	char	c;
	int		ok;
	short	nb_line;

	reste_param();
	if (nb_line = ft_atoi_fd(fd) > 0)
		ok = 1;
	else
		ok = 0;
	param(SIZE_Y, nb_line);
	if (ok && c != '\n')
		par && (VIDE, c);
	if (ok && ok = read(fd, &c, 1) && c != '\n')
		param(OBSTACLE, c); 
	if (ok && ok = read(fd, &c, 1) && c != '\n')
		param(PLEIN, c);
	if (ok && ok = read(fd, &c, 1) && c == '\n')
		return (1);
	else
		return (0);
}
