/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/10 15:15:17 by lguiller         ###   ########.fr       */
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

static int		ft_check_inter(t_vec inter, t_line line)
{
	t_vec	v_wall;
	t_vec	v_inter;

	v_wall = ft_vecsub(line.b, line.a);
	v_inter = ft_vecsub(inter, line.a);
	return (ft_vecnorm(v_inter) < ft_vecnorm(v_wall) &&
		ft_dot_product(v_inter, v_wall) > 0.0);
}

static float	ft_rayintersect(t_vec pos, t_vec raydir, t_zone **zones)
{
	float	dist[2];
	t_vec	inter;
	t_line	l1;
	t_line	l2;
	t_coord	i;

	dist[1] = INFINITY;
	i.x = -1;
	while (zones[++i.x] && (i.y = -1))
		while (zones[i.x]->walls[++i.y])
			if (zones[i.x]->walls[i.y]->nextzone == -1)
			{
				l1 = ft_vec_to_line(ft_vecadd(raydir, pos), pos);
				if (zones[i.x]->walls[i.y + 1])
					l2 = ft_vec_to_line(zones[i.x]->walls[i.y]->origin,
							zones[i.x]->walls[i.y + 1]->origin);
				else
					l2 = ft_vec_to_line(zones[i.x]->walls[i.y]->origin,
							zones[i.x]->walls[0]->origin);
				inter = ft_vec_intersection(l1, l2);
				if (ft_check_inter(inter, l2))
				{
					inter = ft_vecsub(inter, pos);
					dist[0] = ft_vecnorm(inter);
					if (dist[0] < dist[1]
						&& ft_dot_product(inter, raydir) > 0.0)
						dist[1] = dist[0];
				}
			}
	return (dist[1]);
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
		p.y = -1;
		if (inter != INFINITY && inter != 0.0)
		{
			while (++p.y < inter / 2.0 && p.y >= 0.0 && p.y < img->height)
			{
				px_to_img(img, p.x, (img->height / 2.0) + p.y, 0xFFFFFF);
				px_to_img(img, p.x, (img->height / 2.0) - p.y, 0xFFFFFF);
			}
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
