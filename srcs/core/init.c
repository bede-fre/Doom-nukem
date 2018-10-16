/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:15:20 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/16 17:04:44 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		playerinit(t_doom *env)
{
	env->player.pos = ft_vecdef(10.0, 10.0, 0.0);
	env->player.body = ft_vecdef(0.0, -1.0, 0.0);
	env->player.head = env->player.body;
	env->angle = ft_vec_angle(ft_vecdef(0.0, -1.0, 0.0), env->player.body);
	env->player.speed = 0.1;
}

void			init(t_doom *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("Failed to initalize the mlx");
	if (!(env->window = mlx_new_window(env->mlx, WIN_WIDTH,
					WIN_HEIGHT, "doom-nukem")))
		ft_error("MLX failed to create a window");
	mlx_clear_window(env->mlx, env->window);
	playerinit(env);
	env->param.sensitivity = 0.3;
	env->param.mousepos = ft_vecdef(-6000.0, -6000.0, 0.0);
	mapinit(env);
//	mapimgalloc(env->zone, &env->map, env);
	img_get(&env->img, WIN_WIDTH, WIN_HEIGHT, env);
	img_get(&env->minimap, MAP_WIDTH, MAP_HEIGHT, env);
}
