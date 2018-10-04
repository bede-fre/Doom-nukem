/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/04 11:26:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int							ft_printrays(t_doom *env, t_img *img)
{
	float					increment;
	t_vec					raydir;
	int						i;

	increment = FOV / WIN_WIDTH;
	raydir = ft_vecrotz(env->player.rot, -(FOV / 2));
	i = 0;
	while (i < WIN_WIDTH)
	{
		ft_putline(ft_vecscale(env->player.pos, 10), ft_vecadd(ft_vecscale(env->player.pos, 10), ft_vecscale(raydir, 10)), img, 0xaaff00);
//		ft_putline(ft_vecscale(env->player.pos, 10), ft_vecscale(ft_vecadd(env->player.pos, raydir), 20), &env->img, 0xaaff00);
		raydir = ft_vecrotz(raydir, increment);
		i++;
	}
	return (1);
}

int							ft_printplayer(t_doom *env, t_img *img)
{
	t_vec					playerpos;

	playerpos = ft_vecscale(env->player.pos, 10);
	px_to_img(img, playerpos.x, playerpos.y, 0xffff00);
	ft_printrays(env, img);
	return (1);
}

int							ft_printmap(t_doom *env, t_img *img)
{
//	merge_images(img, &env->map, 0, 0);
	rotmapimgalloc(env->zones, &env->minimap, env);
	return (1);
}

static float				ft_rayintersect(t_vec pos, t_vec raydir, t_zone **zones, t_doom *env)
{
	t_vec	wall_dir;
	t_vec	vec;
	int		i;
	float	dist;
	float	t;

	dist = INFINITY;
	vec = ft_vecdef(0.0, 0.0, 1.0);
	i = -1;
	while (zones[0]->walls[++i])
	{
		wall_dir = ft_cross_product(zones[0]->walls[i]->direction, vec);
		t = -(((wall_dir.x * (pos.x - zones[0]->walls[i]->origin.x)) +
			(wall_dir.y * (pos.y - zones[0]->walls[i]->origin.y)) +
			(wall_dir.z * (pos.z - zones[0]->walls[i]->origin.z))) /
			((wall_dir.x * raydir.x) +
			(wall_dir.y * raydir.y) +
			(wall_dir.z * raydir.z)));
		if (t >= 0.0 && t < dist)
			dist = t;
	}
	dist = 10.0 / dist * 32.0;
	return (dist);
}

static void					ft_make_view(t_doom *env, t_img *img)
{
	float					increment;
	t_vec					raydir;
	int						i;
	float					intersect;
	float					angle;
	float					testcos;

	increment = FOV / WIN_WIDTH;
	raydir = ft_vecrotz(env->player.rot, -(FOV / 2));
	i = 0;
	bzero(img->data, img->width * img->height * 4);
	angle = -(FOV / 2);
	while (i < WIN_WIDTH)
	{
		intersect = ft_rayintersect(env->player.pos, raydir, env->zones, env);
		if (intersect != INFINITY)
		{
			if (intersect != 0)
			{
				ft_putline(ft_vecdef((float)i, ((img->height / 2.0) - intersect), 0.0),
				ft_vecdef((float)i, ((img->height / 2.0) + intersect), 0.0), img, 0xffffff);
			}
		}
		angle += increment;
		raydir = ft_vecrotz(raydir, increment);
		i++;
	}
}

void						render(t_doom *doom)
{
	bzero(doom->img.data, doom->img.width * doom->img.height * 4);
	playermove(doom);
	ft_make_view(doom, &doom->img);
	ft_printmap(doom, &doom->img);
//	ft_printplayer(doom, &doom->img);
	mlx_put_image_to_window(doom->mlx ,doom->window, doom->img.ptr, 0, 0);
	mlx_put_image_to_window(doom->mlx, doom->window, doom->minimap.ptr, 0, 0);
//	mlx_put_image_to_window(doom->mlx, doom->window, doom->view.ptr, 300, 300);
	//	printf("Render\n");
}
