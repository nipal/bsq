/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 19:06:26 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:06:28 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FT_H
# define FT_FT_H

# include <unistd.h>

int		ft_strlen(char *str);
void	ft_puterror(char *str);
void	ft_putstr(unsigned char *str, int nb_char);
void	putnbr62(short nbr);

# define CHAINE "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

#endif
