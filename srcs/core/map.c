/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:18 by toliver           #+#    #+#             */
/*   Updated: 2018/10/05 17:39:15 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void			mapdraw(t_zone **zones, t_img *map)
{
	int				i;
	int				ii;

	i = 0;
	while (zones[i])
	{	
		ii = 0;
		while (zones[i]->walls[ii])
		{
			if (zones[i]->walls[ii + 1])
				ft_putline(ft_vecscale(zones[i]->walls[ii]->origin, 10),
						ft_vecscale(zones[i]->walls[ii + 1]->origin, 10),
						map, 0xcccccc);
			else
				ft_putline(ft_vecscale(zones[i]->walls[ii]->origin, 10),
						ft_vecscale(zones[i]->walls[0]->origin, 10),
						map, 0xcccccc);
			ii++;
		}
		i++;
	}
}

void				mapimgalloc(t_zone **zones, t_img *map, t_doom *env)
{
	int				i;
	int				ii;
	float			maxx;
	float			maxy;
	
	i = 0;
	maxx = 0;
	maxy = 0;
	while (zones[i])
	{	
		ii = 0;
		while (zones[i]->walls[ii])
		{
			if (zones[i]->walls[ii]->origin.x > maxx)
				maxx = zones[i]->walls[ii]->origin.x;
			if (zones[i]->walls[ii]->origin.y > maxy)
				maxy = zones[i]->walls[ii]->origin.y; 
			ii++;
		}
		i++;
	}
	img_get(map, (int)(maxx * 10 + 1), (int)(maxy * 10 + 1), env);
	mapdraw(zones, map);
}

static int			ft_printrays(t_img *img)
{
	float					increment;
	t_vec					center;
	t_vec					raydir;
	int						i;

	center = ft_vecdef(MAP_WIDTH / 2, MAP_HEIGHT / 2 - 5, 0);
	increment = FOV / WIN_WIDTH;
	raydir = ft_vecrotz(ft_vecdef(0, 1, 0), -(FOV / 2));
	i = -1;
	while (++i < WIN_WIDTH)
	{
		ft_putline(center, ft_vecadd(center, ft_vecscale(raydir, 10)), img, 0xaaff00);
		raydir = ft_vecrotz(raydir, increment);
	}
	return (1);
}

static void			maprotdraw(t_zone **zones, t_img *map, t_doom *env)
{
	t_vec			p1;
	t_vec			p2;
	t_vec			center;
	int				i;
	int				ii;

	center = ft_vecdef(100.0, 100.0, 0.0);
	i = 0;
	while (zones[i])
	{
		ii = 0;
		while (zones[i]->walls[ii])
		{
			p1 = ft_vecsub(ft_vecscale(zones[i]->walls[ii]->origin, 10.0),
					ft_vecscale(env->player.pos, 10.0));
			p1 = ft_vecrotz(p1, -env->angle);
			p1 = ft_vecadd(p1, center);
			if (zones[i]->walls[ii + 1])
				p2 = ft_vecsub(ft_vecscale(zones[i]->walls[ii + 1]->origin, 10.0),
						ft_vecscale(env->player.pos, 10.0));
			else
				p2 = ft_vecsub(ft_vecscale(zones[i]->walls[0]->origin, 10.0),
						ft_vecscale(env->player.pos, 10.0));
			p2 = ft_vecrotz(p2, -env->angle);
			p2 = ft_vecadd(p2, center);
			ft_putline(p1, p2, map, 0xCCCCCC);
			ii++;
		}
		i++;
	}
	ft_printrays(map);
	i = -1;
	while (++i < 200 && (ii = -1))
		while (++ii < 200)
			if (i == 0 || ii == 0 || i == MAP_WIDTH - 1 || ii == MAP_HEIGHT - 1)
				px_to_img(map, i, ii, 0xFFFFFF);
}

void				rotmapimgalloc(t_zone **zones, t_img *map, t_doom *env)
{
	img_get(map, 200, 200, env);
	maprotdraw(zones, map, env);
}
