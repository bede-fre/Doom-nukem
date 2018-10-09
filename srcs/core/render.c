/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/09 16:39:47 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
static void		ft_printrays(t_doom *env, t_img *img)
{
	float	increment;
	t_vec	raydir;
	int		i;

	increment = FOV / (float)WIN_WIDTH;
	raydir = ft_vecrotz(env->player.rot, -(FOV / 2.0));
	i = -1;
	while (++i < WIN_WIDTH)
	{
		ft_putline(ft_vecscale(env->player.pos, 10.0),
			ft_vecadd(ft_vecscale(env->player.pos, 10.0),
			ft_vecscale(raydir, 10.0)), img, 0xaaff00);
		raydir = ft_vecrotz(raydir, increment);
	}
}

int				ft_printplayer(t_doom *env, t_img *img)
{
	t_vec	playerpos;

	playerpos = ft_vecscale(env->player.pos, 10.0);
	px_to_img(img, playerpos.x, playerpos.y, 0xffff00);
	ft_printrays(env, img);
	return (1);
}
*/

static float	ft_rayintersect(t_vec pos, t_vec raydir, t_zone **zones)
{
	int		i;
	float	dist;
	float	t;
	t_vec	inter;

	dist = INFINITY;
	i = -1;
	while (zones[0]->walls[++i])
	{
		inter = ft_vec_intersection(raydir, pos, zones[0]->walls[i]->direction,
			zones[0]->walls[i]->origin);
		inter = ft_vecsub(inter, pos);
		t = ft_vecnorm(inter);
		if (t < dist && ft_dot_product(inter, raydir) > 0.0)
			dist = t;
	}
	return (dist);
}

static void		ft_make_view(t_doom *env, t_img *img)
{
	t_coord	p;
	t_vec	raydir;
	float	angle;
	float	inter;
	float	i;

	i = FOV / WIN_WIDTH;
	raydir = ft_vecrotz(env->player.rot, -(FOV / 2.0));
	bzero(img->data, img->width * img->height * 4);
	angle = -(FOV / 2.0);
	p.x = -1;
	while (++p.x < WIN_WIDTH)
	{
		inter = (((float)env->img.width / 2.0) / tanf(ft_degtorad(FOV / 2.0)) /
			(ft_rayintersect(env->player.pos, raydir, env->zones) *
			cosf(ft_degtorad(angle))));
		if (inter != INFINITY && inter != 0.0)
		{
			p.y = img->height / 2.0 - inter / 2.0;
			while (++p.y <= img->height / 2.0 + inter / 2.0)
				px_to_img(img, p.x, p.y, 0xFFFFFF);
		}
		angle += i;
		raydir = ft_vecrotz(raydir, i);
	}
}

void			render(t_doom *doom)
{
	bzero(doom->img.data, doom->img.width * doom->img.height * 4);
	playermove(doom);
	ft_make_view(doom, &doom->img);
	rotmapimgalloc(doom->zones, &doom->minimap, doom);
//	ft_printplayer(doom, &doom->img);
	mlx_put_image_to_window(doom->mlx, doom->window, doom->img.ptr, 0, 0);
	mlx_put_image_to_window(doom->mlx, doom->window, doom->minimap.ptr, 0, 0);
}
