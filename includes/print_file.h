/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fike.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:50:07 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/05 19:16:27 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FILE_H
# define PRINT_FILE_H

# include <stdlib.h>
# include "ft_liste.h"

typedef	unsigned	int	t_bin;
short	param(short action, short valu);
void	ft_print_file(char *name);
void	reste_param(void);
short	ft_atoi_fd(fd);
int		init_param(int fd);
void	get_first_line(t_list **line, int fd);
void	copie_first_line(t_bin **tab, t_list *first_line);
t_bin	*malloc_line(void);
#endif

