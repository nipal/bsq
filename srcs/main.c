/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/10 20:01:56 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	short	err;
	short	i;

	i = 1;
	if (ac == 1)
	{
		err = ft_print_file(0);
		if (err == -1)
			ft_puterror("map error\n");
		else if (err == -2)
			ft_puterror("memory error\n");
		dprintf(1, "non");
	}
	while (i < ac)
	{
		err = ft_print_file(av[i]);
		if (err == -1)
			ft_puterror("map error\n");
		else if (err == -2)
			ft_puterror("memory error\n");
		i++;
	}
	return (0);
}
