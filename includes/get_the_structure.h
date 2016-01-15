/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_structure.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 19:05:57 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:06:00 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_THE_STRUCTURE_H
# define GET_THE_STRUCTURE_H

# include <stdlib.h>
# include "t_bin.h"
# include "init_val.h"
# include <unistd.h>

int		fill_the_char(char c, t_bin *line_b, int init);
int		get_the_structure(t_bin **tab, int fd, int x_max, int y_max);
int		fill_the_char(char c, t_bin *line_b, int init);

#endif
