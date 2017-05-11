/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <jschotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:55:53 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 16:28:29 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display_help(void)
{
	ft_putendl("Usage: ./fractol <number>");
	ft_putendl("1: Julia");
	ft_putendl("2: Mandelbrot");
	ft_putendl("3: Sierpinski carpet");
	ft_putendl("4: Sierpinski triangle");
	ft_putendl("5: Burning Ship");
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_display_help();
	else if (ft_strcmp(av[1], "1") == 0)
		ft_init(1);
	else if (ft_strcmp(av[1], "2") == 0)
		ft_init(2);
	else if (ft_strcmp(av[1], "3") == 0)
		ft_init(3);
	else if (ft_strcmp(av[1], "4") == 0)
		ft_init(4);
	else if (ft_strcmp(av[1], "5") == 0)
		ft_init(5);
	else
		ft_display_help();
	return (0);
}
