/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:50:56 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/22 14:25:23 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	ft_printrays(t_img *img)
{
	int		i;
	t_vec	center;
	t_vec	raydir;
	float	increment;

	center = ft_vecdef((float)MAP_WIDTH / 2.0f,
		(float)MAP_HEIGHT / 2.0f - 5.0f, 0.0f);
	increment = FOV / (float)WIN_WIDTH;
	raydir = ft_vecrotz(ft_vecdef(0.0f, 1.0f, 0.0f), -(FOV / 2.0f));
	i = -1;
	while (++i < WIN_WIDTH)
	{
		ft_putline(center, ft_vecadd(center, ft_vecscale(raydir, 10.0f)), img,
			0xAAFF00);
		raydir = ft_vecrotz(raydir, increment);
	}
}

static void	print_walls(t_wall *wall, t_img *map, t_doom *env)
{
	t_vec	p1;
	t_vec	p2;
	t_vec	center;

	center = ft_vecdef(100.0f, 100.0f, 0.0f);
	p1 = ft_vecsub(ft_vecscale(wall->origin, 10.0f),
			ft_vecscale(env->player.pos, 10.0f));
	p1 = ft_vecrotz(p1, -env->angle);
	p1 = ft_vecadd(p1, center);
	p2 = ft_vecsub(ft_vecscale(wall->next->origin,
		10.0f), ft_vecscale(env->player.pos, 10.0f));
	p2 = ft_vecrotz(p2, -env->angle);
	p2 = ft_vecadd(p2, center);
	ft_putline(p1, p2, map, 0xCCCCCC);
}

static void	make_border(t_img *map)
{
	t_coord	p;

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

void		rotmapimgalloc(t_zone *zone, t_img *map, t_doom *env)
{
	int		i;
	t_zone	*tmp_z;
	t_wall	*tmp_w;

	img_get(map, MAP_WIDTH, MAP_HEIGHT, env);
	tmp_z = zone;
	while (tmp_z)
	{
		i = -1;
		tmp_w = tmp_z->wall;
		while (tmp_w->num != tmp_z->wall->num || !(++i))
		{
			print_walls(tmp_w, map, env);
			tmp_w = tmp_w->next;
		}
		tmp_z = tmp_z->next;
	}
	ft_printrays(map);
	make_border(map);
}
