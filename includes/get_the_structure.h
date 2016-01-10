/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_sructure.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty </var/mail/fjanoty>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 02:30:26 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 04:12:54 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_THE_STRUCTURE_H
# define GET_THE_STRUCTURE_H

# include <stdlib.h>
# include "t_bin.h"
# include "init_val.h"
# include <unistd.h>

short	fill_the_char(char c, t_bin *line_b, t_bin max, short init);
short	get_the_structure(t_bin **tab, int fd, short x_max, short y_max);
short	fill_the_char(char c, t_bin *line_b, t_bin max, short init);

#endif
