/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <jschotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:26:19 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 09:22:42 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*str;

	str = img->data + (img->bbp / 8) * x + y * img->size_line;
	*str = color;
	*++str = (color >> 8);
	*++str = (color >> 16);
}

void	ft_square(t_env *e)
{
	int i;
	int j;

	i = 490;
	while (i < 790)
	{
		j = 40;
		while (j < 220)
		{
			put_pixel_to_image(&e->img, i, j, 0x969696);
			j++;
		}
		i++;
	}
}

void	ft_commands(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 490, 40, 0x00FFFF,
		"Use arrows to Move");
	mlx_string_put(e->mlx, e->win, 490, 60, 0x00FF00,
		"Use + or - to change iteration");
	mlx_string_put(e->mlx, e->win, 490, 80, 0xFF0000,
		"Press	 SPACE to change fractal");
	mlx_string_put(e->mlx, e->win, 490, 100, 0xFFAA00,
		"Use wheel to zoom");
	mlx_string_put(e->mlx, e->win, 490, 120, 0xFF00AA,
		"Use the mouse to vary Julia");
	mlx_string_put(e->mlx, e->win, 490, 140, 0xFFFF00,
		"Press ENTER to lock Julia");
	mlx_string_put(e->mlx, e->win, 490, 160, 0xAAF00F,
		"Press r to reset fractal");
	mlx_string_put(e->mlx, e->win, 490, 180, 0x00FFAA,
		"Press h to remove help");
	mlx_string_put(e->mlx, e->win, 490, 200, 0xFF00FF,
		"Press esc to exit");
}

void	draw(t_env *env)
{
	t_img	img;

	img.ptr = mlx_new_image(env->mlx, WIN_X, WIN_Y);
	img.data = mlx_get_data_addr(img.ptr, &img.bbp,
			&img.size_line, &img.endian);
	env->img = img;
	if (env->nb == 1)
		ft_julia(env);
	else if (env->nb == 2)
		ft_mandel(env);
	else if (env->nb == 3)
		ft_carpet(env);
	else if (env->nb == 4)
		ft_triforce(env, 150, 550, 500);
	else
		ft_mandel_abs(env);
	if (env->frac.help == 1)
		ft_square(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.ptr,
			env->frac.x, env->frac.y);
	if (env->frac.help == 1)
		ft_commands(env);
	mlx_destroy_image(env->mlx, env->img.ptr);
}

void	ft_init(int nb)
{
	t_env	env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "42");
	env.nb = nb;
	env.frac = init_fractal(&env);
	env.frac.
	help = 1;
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_mouse_hook(env.win, mouse, &env);
	mlx_hook(env.win, 6, (1L << 6), mouse_hook, &env);
	mlx_hook(env.win, 17, 0, close_hook, &env);
	mlx_loop(env.mlx);
}
