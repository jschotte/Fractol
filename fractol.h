/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 16:04:56 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 14:51:32 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_X 800
# define WIN_Y 600
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>

typedef struct	s_fracal
{
	int				max_i;
	double			minim;
	double			maxim;
	double			minre;
	double			maxre;
	double			re_f;
	double			im_f;
	double			im_c;
	double			re_c;
	double			im_z;
	double			im_z2;
	double			re_z;
	double			re_z2;
	double			x;
	double			y;
	double			zoom;
	double			k;
	int				lock;
	int				help;
}				t_fractal;

typedef struct	s_img
{
	void			*ptr;
	char			*data;
	int				bbp;
	int				size_line;
	int				endian;
}				t_img;

typedef struct	s_env
{
	void				*mlx;
	void				*win;
	struct s_img		img;
	int					nb;
	t_fractal			frac;
}				t_env;

void			ft_init(int nb);
void			put_pixel_to_image(t_img *img, int x, int y, int color);
t_fractal		init_fractal(t_env *env);
int				ft_exit(t_env *env);

void			draw(t_env *env);

int				expose_hook(t_env *env);
int				key_hook(int keycode, t_env *env);
int				mouse(int key, int x, int y, t_env *env);
int				mouse_hook(int x, int y, t_env *env);
int				close_hook(int but, t_env *env);

void			ft_julia(t_env *env);
void			ft_mandel(t_env *env);
void			ft_carpet(t_env *env);
void			ft_triforce(t_env *env, int x, int y, int l);
void			ft_mandel_abs(t_env *env);

#endif
