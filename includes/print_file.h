/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:50:07 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:00:02 by fjanoty          ###   ########.fr       */
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
# include "search_the_big_one.h"
# include "print_the_result.h"
# include <sys/types.h>
# include <sys/stat.h>

int		param(int action, int valu);
int		ft_print_file(char *name);
void	reste_param(void);
int		init_param(int fd);
t_bin	*malloc_line(int nb_var);
#endif
