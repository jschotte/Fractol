/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 09:33:11 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 09:33:14 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *env)
{
	draw(env);
	return (0);
}

void	key_hook_next(int keycode, t_env *env)
{
	if (keycode == 123)
		env->frac.minre /= 1.1;
	else if (keycode == 124)
		env->frac.minre *= 1.1;
	else if (keycode == 49)
	{
		env->nb++;
		if (env->nb > 5)
			env->nb = 1;
		env->frac = init_fractal(env);
	}
	else if (keycode == 15)
		env->frac = init_fractal(env);
	else if (keycode == 36)
	{
		if (env->frac.lock == 0)
			env->frac.lock = 1;
		else
			env->frac.lock = 0;
	}
	else if (keycode == 4 && env->frac.help == 0)
		env->frac.help = 1;
	else if (keycode == 4 && env->frac.help == 1)
		env->frac.help = 0;
}

int		key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		ft_exit(env);
	else if (keycode == 69)
	{
		if (env->nb != 4 && env->frac.max_i < 1000)
			env->frac.max_i += 10;
		else if (env->nb == 4 && env->frac.max_i < 9)
			env->frac.max_i++;
	}
	else if (keycode == 78)
	{
		if (env->nb != 4 && env->frac.max_i > 10)
			env->frac.max_i -= 10;
		else if (env->nb == 4 && env->frac.max_i > 1)
			env->frac.max_i--;
	}
	else if (keycode == 125)
		env->frac.minim -= 0.1;
	else if (keycode == 126)
		env->frac.minim += 0.1;
	key_hook_next(keycode, env);
	draw(env);
	return (0);
}

int		mouse(int key, int x, int y, t_env *env)
{
	x = 0;
	y = 0;
	if (key == 5)
		env->frac.zoom *= 1.1;
	else if (key == 4)
		env->frac.zoom /= 1.1;
	draw(env);
	return (0);
}

int		mouse_hook(int x, int y, t_env *env)
{
	y = 0;
	if (env->frac.lock == 0)
	{
		if (x > WIN_X / 2 && env->frac.k < 2.2)
			env->frac.k += 0.1;
		else if (env->frac.k > 0)
			env->frac.k -= 0.1;
		draw(env);
	}
	return (0);
}
