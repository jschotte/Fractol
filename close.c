/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:44:51 by jschotte          #+#    #+#             */
/*   Updated: 2017/05/10 16:44:59 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

int		close_hook(int but, t_env *env)
{
	(void)but;
	(void)env;
	exit(0);
}
