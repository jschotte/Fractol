/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 09:42:46 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 09:42:49 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_julia_next(t_env *env, int x, int y)
{
	int		n;

	env->frac.re_z = env->frac.re_c;
	env->frac.im_z = env->frac.im_c;
	n = 0;
	while (n < env->frac.max_i)
	{
		env->frac.re_z2 = env->frac.re_z * env->frac.re_z;
		env->frac.im_z2 = env->frac.im_z * env->frac.im_z;
		if (env->frac.re_z2 + env->frac.im_z2 > 4)
			break ;
		env->frac.im_z = 2 * env->frac.re_z * env->frac.im_z
			+ 0.353 + env->frac.k * env->frac.im_z;
		env->frac.re_z = env->frac.re_z2 - env->frac.im_z2
			+ 0.353 + env->frac.k * env->frac.re_z;
		n++;
	}
	put_pixel_to_image(&env->img, x, y, (0xFF009F * n)
					/ (env->frac.max_i / 2));
}

void		ft_julia(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		env->frac.im_c = env->frac.maxim - y * env->frac.im_f;
		while (x < WIN_X)
		{
			env->frac.re_c = env->frac.minre + (x * env->frac.re_f)
				/ env->frac.zoom;
			env->frac.im_c = env->frac.minim + (y * env->frac.im_f)
				/ env->frac.zoom;
			ft_julia_next(env, x, y);
			++x;
		}
		++y;
	}
}
