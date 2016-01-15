/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 19:06:11 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:06:12 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_VAL_H
# define INIT_VAL_H

# include <unistd.h>
# define SIZE_X	2
# define SIZE_Y	4
# define VIDE 8
# define OBSTACLE 16
# define PLEIN 32

int		param(int action, int valu);
void	reste_param(void);
int		ft_atoi_fd(int fd, char *c);
int		init_param(int fd);

#endif
