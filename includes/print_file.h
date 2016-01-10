/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:50:07 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 04:30:04 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FILE_H
# define PRINT_FILE_H

# include "t_bin.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_list.h"
# include "first_line.h"
# include "copie_first_line.h"
# include "init_val.h"

short	param(short action, short valu);
short	ft_print_file(char *name);
void	reste_param(void);
int		init_param(int fd);
t_bin	*malloc_line(short nb_var);
#endif

