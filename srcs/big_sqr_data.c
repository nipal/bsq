/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sqr_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty </var/mail/fjanoty>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 16:53:16 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 17:41:06 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "search_the_big_one.h"

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

void			increm_max(short *line_work, short j, short i)
{
	if (line_work[i] >=  (big_sqr_data(SIZE, 0)) + 1)
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
