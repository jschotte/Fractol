/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 09:42:53 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 15:10:28 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_fabs(double f)
{
	if (f < 0)
		return (f * -1);
	else
		return (f);
}

void		ft_abs_next(t_env *env, int x, int y)
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
		env->frac.im_z = ft_fabs(2 * env->frac.re_z * env->frac.im_z)
			+ env->frac.im_c;
		env->frac.re_z = env->frac.re_z2 - env->frac.im_z2
			+ env->frac.re_c;
		n++;
	}
	put_pixel_to_image(&env->img, x, y, (0xFF009F * n)
			/ (env->frac.max_i / 2));
}

void		ft_mandel_abs(t_env *env)
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
			ft_abs_next(env, x, y);
			++x;
		}
		++y;
	}
}
