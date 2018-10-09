/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:15:20 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/09 15:27:30 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static	t_zone	*malloczone(void)
{
	t_zone	*zone;

	zone = (t_zone*)ft_memalloc(sizeof(t_zone));
	zone->walls = (t_wall**)ft_memalloc(sizeof(t_wall*) * 6);
	zone->walls[0] = get_wall(0, -1, ft_vecdef(0.0, 0.0, 0.0),
		ft_vecdef(1.0, 0.0, 0.0));
	zone->walls[1] = get_wall(0, -1, ft_vecdef(20.0, 0.0, 0.0),
		ft_vecdef(0.0, 1.0, 0.0));
	zone->walls[2] = get_wall(0, -1, ft_vecdef(20.0, 20.0, 0.0),
		ft_vecdef(-0.5, 0.5, 0.0));
	zone->walls[3] = get_wall(0, -1, ft_vecdef(10.0, 30.0, 0.0),
		ft_vecdef(-0.5, -0.5, 0.0));
	zone->walls[4] = get_wall(0, -1, ft_vecdef(0.0, 20.0, 0.0),
		ft_vecdef(0.0, -1.0, 0.0));
	zone->walls[5] = NULL;
	return (zone);
}

static void		mapinit(t_doom *env)
{
	env->zones = (t_zone**)malloc(sizeof(t_zone*) * 2);
	env->zones[1] = NULL;
	env->zones[0] = malloczone();
	mapimgalloc(env->zones, &env->map, env);
}

static void		playerinit(t_doom *env)
{
	env->player.pos = ft_vecdef(10.0, 10.0, 0.0);
	env->player.rot = ft_vecdef(0.0, -1.0, 0.0);
	env->angle = ft_vec_angle(ft_vecdef(0.0, -1.0, 0.0), env->player.rot);
	env->player.rotangle = ft_vecdef(0.0, 0.0, -90.0);
	env->player.speed = 0.1;
}

static void		imginit(t_doom *env)
{
	img_get(&env->img, WIN_WIDTH, WIN_HEIGHT, env);
	img_get(&env->minimap, MAP_WIDTH, MAP_HEIGHT, env);
}

void			init(t_doom **env)
{
	t_doom	*doom;

	doom = (t_doom*)ft_memalloc(sizeof(t_doom));
	if (!(doom->mlx = mlx_init()))
		ft_error("Failed to initalize the mlx");
	if (!(doom->window = mlx_new_window(doom->mlx, WIN_WIDTH,
	WIN_HEIGHT, "doom-nukem")))
		ft_error("MLX failed to create a window");
	mlx_clear_window(doom->mlx, doom->window);
	playerinit(doom);
	doom->param.sensitivity = 0.3;
	doom->param.mousepos = ft_vecdef(-6000.0, -6000.0, 0.0);
	mapinit(doom);
	imginit(doom);
	*env = doom;
}
