/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_the_big_one.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty </var/mail/fjanoty>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 02:07:31 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 05:14:21 by fjanoty          ###   ########.fr       */
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

short			big_sqr_data(short mode, short value);
short			search_the_big_one(t_bin **tab, short y_max, short j);

#endif
