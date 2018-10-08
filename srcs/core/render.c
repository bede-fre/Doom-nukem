/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/08 16:44:56 by bede-fre         ###   ########.fr       */
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
		ft_putline(ft_vecscale(env->player.pos, 10),
		ft_vecadd(ft_vecscale(env->player.pos, 10),
		ft_vecscale(raydir, 10)), img, 0xaaff00);
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
	(void)img;
//	merge_images(img, &env->map, 0, 0);
	rotmapimgalloc(env->zones, &env->minimap, env);
	return (1);
}

static float				ft_rayintersect(t_vec pos, t_vec raydir, t_zone **zones)
{
	int		i;
	float	dist;
	float	t;
	t_vec	inter;

	dist = INFINITY;
	i = -1;
	while (zones[0]->walls[++i])
	{
		inter = ft_vec_intersection(raydir, pos, zones[0]->walls[i]->direction, zones[0]->walls[i]->origin);
		inter = ft_vecsub(inter, pos);
		t = ft_vecnorm(inter);
		if (t < dist && ft_dot_product(inter, raydir) > 0.0)
			dist = t;
	}
	return (dist);
}

static void					ft_make_view(t_doom *env, t_img *img)
{
	float					increment;
	t_vec					raydir;
	int						i;
	int						j;
	float					intersect;
	float					angle;

	increment = FOV / WIN_WIDTH;
	raydir = ft_vecrotz(env->player.rot, -(FOV / 2));
	i = 0;
	bzero(img->data, img->width * img->height * 4);
	angle = -(FOV / 2);
	while (i < WIN_WIDTH)
	{
		intersect = ft_rayintersect(env->player.pos, raydir, env->zones);
		intersect *= cos(ft_degtorad(angle));
		intersect = ((env->img.width / 2.0) / tan(ft_degtorad(FOV / 2.0)) / intersect);
		if (intersect != INFINITY)
		{
			if (intersect != 0)
			{
				j = -1;
				while (++j <= intersect / 2.0)
				{
					px_to_img(img, i, (img->height / 2.0) + j, 0xFFFFFF);
					px_to_img(img, i, (img->height / 2.0) - j, 0xFFFFFF);
				}
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
	mlx_put_image_to_window(doom->mlx, doom->window, doom->img.ptr, 0, 0);
	mlx_put_image_to_window(doom->mlx, doom->window, doom->minimap.ptr, 0, 0);
//	mlx_put_image_to_window(doom->mlx, doom->window, doom->view.ptr, 300, 300);
	//	printf("Render\n");
}
