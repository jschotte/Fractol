/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 09:12:18 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 09:27:59 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal	init_fractal(t_env *env)
{
	t_fractal tmp;

	tmp.x = 0;
	tmp.y = 0;
	tmp.minre = -2.0;
	tmp.maxre = 1.0;
	tmp.minim = -1.2;
	tmp.maxim = tmp.minim + (tmp.maxre - tmp.minre) * WIN_Y / WIN_X;
	tmp.re_f = (tmp.maxre - tmp.minre) / (WIN_X - 1);
	tmp.im_f = (tmp.maxim - tmp.minim) / (WIN_Y - 1);
	if (env->nb == 4)
		tmp.max_i = 1;
	else
		tmp.max_i = 170;
	tmp.zoom = 1;
	tmp.k = 2;
	tmp.lock = 1;
	tmp.help = 0;
	return (tmp);
}

int			is_filled(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void		ft_carpet(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			if (is_filled(x, y) == 1)
				put_pixel_to_image(&env->img, x, y, 0xFFFFFF);
			++x;
		}
		++y;
	}
}
