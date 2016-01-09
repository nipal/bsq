/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/05 19:13:51 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_puterror("File name missing.\n");
	else if (ac > 2)
		ft_puterror("Too many arguments.\n");
	else
		ft_print_file(av[1]);
	return (0);
}
