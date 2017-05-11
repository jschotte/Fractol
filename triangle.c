/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 08:45:46 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 09:26:37 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_line(int x, int y, int l, t_env *env)
{
	int i;

	i = 0;
	while (i < l)
	{
		put_pixel_to_image(&env->img, x + i, y, 0xFFFF00);
		i++;
	}
}

void		ft_draw_full(int x, int y, int l, t_env *env)
{
	int i;
	int tmp;
	int tmp2;

	i = 0;
	ft_line(x, y, l, env);
	tmp = x;
	tmp2 = l;
	while (i < l)
	{
		put_pixel_to_image(&env->img, tmp + i, y - i - 1, 0xFFFF00);
		ft_line(tmp + i, y - i - 1, tmp2, env);
		if (i % 2 == 0)
			tmp--;
		tmp2--;
		i++;
	}
}

void		ft_draw_empty(int x, int y, int l, t_env *env)
{
	int i;
	int tmp;

	i = 0;
	ft_line(x, y, l, env);
	tmp = x;
	while (i < l)
	{
		put_pixel_to_image(&env->img, tmp + i, y - i - 1, 0xFFFF00);
		if (i % 2 == 0)
			tmp--;
		i++;
	}
	i = 0;
	while (i < l)
	{
		put_pixel_to_image(&env->img, l + x - i - 1, y - i - 1, 0xFFFF00);
		if (i % 2 == 0)
			x++;
		i++;
	}
}

t_env		*ft_env(t_env env)
{
	t_env	*new;

	new = &env;
	new->frac.max_i--;
	return (new);
}

void		ft_triforce(t_env *env, int x, int y, int l)
{
	if (env->frac.max_i > 1)
	{
		ft_triforce(ft_env(*env), x, y, l / 2);
		ft_triforce(ft_env(*env), x + (l / 2), y, l / 2);
		ft_triforce(ft_env(*env), x + (l / 4), y - (l / 2), l / 2);
	}
	else
	{
		ft_draw_full(x, y, l, env);
		ft_draw_full(x, y, l, env);
		ft_draw_full(x, y, l, env);
	}
}
