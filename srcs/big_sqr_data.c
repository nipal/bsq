/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sqr_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 19:11:38 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:22:17 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_the_big_one.h"

int				big_sqr_data(int mode, int value)
{
	static	int		x = 0;
	static	int		y = 0;
	static	int		size = 0;

	if (mode & X)
		return ((mode & SET) ? x = value : x);
	if (mode & Y)
		return ((mode & SET) ? y = value : y);
	if (mode & SIZE)
		return ((mode & SET) ? size = value : size);
	return (0);
}

void			increm_max(int *line_work, int j, int i)
{
	if (line_work[i] >= (big_sqr_data(SIZE, 0)) + 1)
	{
		big_sqr_data(SET | SIZE, line_work[i]);
		big_sqr_data(SET | X, i);
		big_sqr_data(SET | Y, j);
	}
}

void			init_big_sqr(void)
{
	big_sqr_data(SET | SIZE, 0);
	big_sqr_data(SET | X, 0);
	big_sqr_data(SET | Y, 0);
}
