/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:07:51 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/15 19:21:52 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ft.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_puterror(char *str)
{
	write(2, str, ft_strlen(str));
}

void	ft_putstr(unsigned char *str, int nb_char)
{
	write(1, str, nb_char);
}

void	putnbr62(short nbr)
{
	static	char	base[63] = CHAINE;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr >= 62)
		putnbr62(nbr / 62);
	write(1, base + (nbr % 62), 1);
}
