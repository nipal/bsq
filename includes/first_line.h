/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 19:04:50 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:07:21 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_LINE_H
# define FIRST_LINE_H

# include <unistd.h>
# include "init_val.h"
# include "ft_list.h"

void	get_first_line(t_list **line, int fd);
#endif
