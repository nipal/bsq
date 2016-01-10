/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty </var/mail/fjanoty>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 02:22:46 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 02:26:23 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_LINE_H
# define FIRST_LINE_H

# include <unistd.h>
# include "init_val.h"
# include "ft_list.h"

void	get_first_line(t_list **line, int fd);
#endif
