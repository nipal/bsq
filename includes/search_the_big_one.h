/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_the_big_one.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 19:07:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:07:52 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEARCH_THE_BIG_ONE_H
# define SEARCH_THE_BIG_ONE_H

# include "init_val.h"
# include <stdlib.h>
# include "t_bin.h"
# define SET 1
# define X 2
# define Y 4
# define SIZE 8

int				big_sqr_data(int mode, int value);
int				solve(t_bin **tab, int y_max, int x_max);
void			increm_max(int *line_work, int j, int i);
void			init_big_sqr(void);

#endif
