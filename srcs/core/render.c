/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/17 13:19:12 by bede-fre         ###   ########.fr       */
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

static void		find_dist(t_vec pos, t_vec raydir, t_wall *wall, float *inter)
{
	t_line	l1;
	t_line	l2;
	t_vec	p;
	float	tmp;

	l1 = ft_vec_to_line(ft_vecadd(raydir, pos), pos);
	l2 = ft_vec_to_line(wall->origin, wall->next->origin);
	p = ft_vec_intersection(l1, l2);
	if (ft_check_inter(p, l2))
	{
		p = ft_vecsub(p, pos);
		tmp = ft_vecnorm(p);
		if (tmp < *inter
				&& ft_dot_product(p, raydir) > 0.0)
			*inter = tmp;
	}
}

static float	ft_rayintersect(t_vec pos, t_vec raydir, t_zone *zone)
{
	int		i;
	float	inter;
	t_zone	*tmp_z;
	t_wall	*tmp_w;

	inter = INFINITY;
	tmp_z = zone;
	while (tmp_z)
	{
		i = -1;
		tmp_w = tmp_z->wall;
		while (tmp_w->num != tmp_z->wall->num || !(++i))
		{
			if (tmp_w->nextzone == -1)
				find_dist(pos, raydir, tmp_w, &inter);
			tmp_w = tmp_w->next;
		}
		tmp_z = tmp_z->next;
	}
	return (inter);
}

static void		ft_make_view(t_doom *env, t_img *img)
{
	t_coord	p;
	t_vec	raydir;
	t_view	ptr;

	ptr.i = FOV / WIN_WIDTH;
	raydir = ft_vecrotz(env->player.body, -(FOV / 2.0));
	bzero(img->data, img->width * img->height * 4);
	ptr.angle = -(FOV / 2.0);
	p.x = -1;
	while (++p.x < WIN_WIDTH)
	{
		ptr.inter = (((float)(env->img.width / 2)) /
			tanf(ft_degtorad(FOV / 2.0)) /
			(ft_rayintersect(env->player.pos, raydir, env->zone) *
			cosf(ft_degtorad(ptr.angle))));
		p.y = -1;
		if (ptr.inter != INFINITY && ptr.inter != 0.0)
			while (++p.y < ptr.inter / 2.0 && p.y >= 0.0 && p.y < img->height)
			{
				px_to_img(img, p.x, env->wall_center + p.y, 0xFFFFFF);
				px_to_img(img, p.x, env->wall_center - p.y, 0xFFFFFF);
			}
		ptr.angle += ptr.i;
		raydir = ft_vecrotz(raydir, ptr.i);
	}
}

void			render(t_doom *doom)
{
	bzero(doom->img.data, doom->img.width * doom->img.height * 4);
	playermove(doom);
	ft_make_view(doom, &doom->img);
	rotmapimgalloc(doom->zone, &doom->minimap, doom);
	//	ft_printplayer(doom, &doom->img);
	mlx_put_image_to_window(doom->mlx, doom->window, doom->img.ptr, 0, 0);
	mlx_put_image_to_window(doom->mlx, doom->window, doom->minimap.ptr, 0, 0);
}
