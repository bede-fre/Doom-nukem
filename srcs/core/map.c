/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:18 by toliver           #+#    #+#             */
/*   Updated: 2018/10/10 10:50:39 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	mapdraw(t_zone **zones, t_img *map)
{
	t_coord	p;

	p.x = -1;
	while (zones[++p.x])
	{
		p.y = -1;
		while (zones[p.x]->walls[++p.y])
		{
			if (zones[p.x]->walls[p.y + 1])
				ft_putline(ft_vecscale(zones[p.x]->walls[p.y]->origin, 10.0),
					ft_vecscale(zones[p.x]->walls[p.y + 1]->origin, 10.0),
					map, 0xcccccc);
			else
				ft_putline(ft_vecscale(zones[p.x]->walls[p.y]->origin, 10.0),
					ft_vecscale(zones[p.x]->walls[0]->origin, 10.0),
					map, 0xcccccc);
		}
	}
}

void		mapimgalloc(t_zone **zones, t_img *map, t_doom *env)
{
	t_coord	p;
	t_vec	max;

	max.x = 0.0;
	max.y = 0.0;
	p.x = -1;
	while (zones[++p.x])
	{
		p.y = -1;
		while (zones[p.x]->walls[++p.y])
		{
			if (zones[p.x]->walls[p.y]->origin.x > max.x)
				max.x = zones[p.x]->walls[p.y]->origin.x;
			if (zones[p.x]->walls[p.y]->origin.y > max.y)
				max.y = zones[p.x]->walls[p.y]->origin.y;
		}
	}
	img_get(map, (int)(max.x * 10.0 + 1.0), (int)(max.y * 10.0 + 1.0), env);
	mapdraw(zones, map);
}

static void	ft_printrays(t_img *img)
{
	int		i;
	t_vec	center;
	t_vec	raydir;
	float	increment;

	center = ft_vecdef((float)MAP_WIDTH / 2.0,
		(float)MAP_HEIGHT / 2.0 - 5.0, 0.0);
	increment = FOV / (float)WIN_WIDTH;
	raydir = ft_vecrotz(ft_vecdef(0.0, 1.0, 0.0), -(FOV / 2.0));
	i = -1;
	while (++i < WIN_WIDTH)
	{
		ft_putline(center, ft_vecadd(center, ft_vecscale(raydir, 10.0)), img,
			0xaaff00);
		raydir = ft_vecrotz(raydir, increment);
	}
}

static void	print_walls(t_zone **zones, t_img *map, t_doom *env, t_coord p)
{
	t_vec	p1;
	t_vec	p2;
	t_vec	center;

	center = ft_vecdef(100.0, 100.0, 0.0);
	p1 = ft_vecsub(ft_vecscale(zones[p.x]->walls[p.y]->origin, 10.0),
		ft_vecscale(env->player.pos, 10.0));
	p1 = ft_vecrotz(p1, -env->angle);
	p1 = ft_vecadd(p1, center);
	if (zones[p.x]->walls[p.y + 1])
		p2 = ft_vecsub(ft_vecscale(zones[p.x]->walls[p.y + 1]->origin,
			10.0), ft_vecscale(env->player.pos, 10.0));
	else
		p2 = ft_vecsub(ft_vecscale(zones[p.x]->walls[0]->origin, 10.0),
			ft_vecscale(env->player.pos, 10.0));
	p2 = ft_vecrotz(p2, -env->angle);
	p2 = ft_vecadd(p2, center);
	ft_putline(p1, p2, map, 0xCCCCCC);
}

void		rotmapimgalloc(t_zone **zones, t_img *map, t_doom *env)
{
	t_coord	p;

	img_get(map, MAP_WIDTH, MAP_HEIGHT, env);
	p.x = -1;
	while (zones[++p.x])
	{
		p.y = -1;
		while (zones[p.x]->walls[++p.y])
			print_walls(zones, map, env, p);
	}
	ft_printrays(map);
	p.x = -1;
	while (++p.x < MAP_WIDTH)
	{
		p.y = -1;
		while (++p.y < MAP_HEIGHT)
			if (p.x == 0 || p.y == 0 || p.x == MAP_WIDTH - 1
				|| p.y == MAP_HEIGHT - 1)
				px_to_img(map, p.x, p.y, 0xFFFFFF);
	}
}
