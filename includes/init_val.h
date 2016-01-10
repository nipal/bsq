/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_val.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty </var/mail/fjanoty>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 02:13:55 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 17:37:15 by fjanoty          ###   ########.fr       */
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

short	param(short action, short valu);
void	reste_param(void);
char	ft_atoi_fd(int fd);
int		init_param(int fd);

#endif
