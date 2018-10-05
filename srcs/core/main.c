/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:32:23 by toliver           #+#    #+#             */
/*   Updated: 2018/10/05 17:31:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_zone				*malloczonetest(void)
{
	t_zone			*zone;

	zone = (t_zone*)ft_memalloc(sizeof(t_zone));
	zone->walls = (t_wall**)ft_memalloc(sizeof(t_wall*) * 6);
	zone->walls[0] = get_wall(0, -1, ft_vecdef(0, 0, 0), ft_vecdef(1, 0, 0));
	zone->walls[1] = get_wall(0, -1, ft_vecdef(20, 0, 0), ft_vecdef(0, 1, 0));
	zone->walls[2] = get_wall(0, -1, ft_vecdef(20, 20, 0), ft_vecdef(-0.5, 0.5, 0));
	zone->walls[3] = get_wall(0, -1, ft_vecdef(10, 30, 0), ft_vecdef(-0.5, -0.5, 0));
	zone->walls[4] = get_wall(0, -1, ft_vecdef(0, 20, 0), ft_vecdef(0, -1, 0));
	zone->walls[5] = NULL;
	return (zone);
}

static void			mapinit(t_doom *env)
{
	env->zones = (t_zone**)malloc(sizeof(t_zone*) * 2);
	env->zones[1] = NULL;
	env->zones[0] = malloczonetest();
	mapimgalloc(env->zones, &env->map, env);
}

static void			playerinit(t_doom *env)
{
	env->player.pos = ft_vecdef(10, 10, 0);
	env->player.rot = ft_vecdef(0, -1, 0);
	env->angle = ft_vec_angle(ft_vecdef(0.0, -1.0, 0.0), env->player.rot);
	env->player.rotangle = ft_vecdef(0, 0, -90);
	env->player.speed = 0.1;
}

static void			imginit(t_doom *env)
{
	img_get(&env->img, WIN_WIDTH, WIN_HEIGHT, env);
	img_get(&env->minimap, MAP_WIDTH, MAP_HEIGHT, env);
	img_get(&env->view, WIN_WIDTH, WIN_HEIGHT, env);
}

static void			init(t_doom **env)
{
	t_doom			*doom;

	doom = (t_doom*)ft_memalloc(sizeof(t_doom));
	if (!(doom->mlx = mlx_init()))
		ft_error("Failed to initalize the mlx");
	if (!(doom->window = mlx_new_window(doom->mlx, WIN_WIDTH,
	WIN_HEIGHT, "doom-nukem")))
		ft_error("MLX failed to create a window");
	mlx_clear_window(doom->mlx, doom->window);
	playerinit(doom);
	doom->param.sensitivity = 0.3;
	doom->param.mousepos = ft_vecdef(-6000, -6000, 0);
	mapinit(doom);
	imginit(doom);
	*env = doom;
}

int					main(void)
{
	t_doom			*env;

	init(&env);
	loop(env);
	return (0);
}
