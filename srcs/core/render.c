/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/26 10:01:18 by lguiller         ###   ########.fr       */
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
	merge_images(img, &env->map, 0, 0);
	return (1);
}

static void					ft_make_minimap(t_doom *env, t_img *img)
{
	t_vec	vect;
	int	x;
	int	y;
	int	i;
	int	j;

	i = (int)(env->player.pos.x * 10.0 - (float)MAP_WIDTH / 2.0);
	j = (int)(env->player.pos.y * 10.0 - (float)MAP_HEIGHT / 2.0);
	x = -1;
	while (++x < MAP_WIDTH)
	{
		y = -1;
		while (++y < MAP_HEIGHT)
		{
			vect = ft_vecdef((float)x - (float)MAP_WIDTH / 2.0, (float)y - (float)MAP_HEIGHT / 2.0, 0);
			vect = ft_vecrotz(vect, env->angle);
			vect.x += env->player.pos.x * 10.0;
			vect.y += env->player.pos.y * 10.0;
			if (vect.x < 0 || vect.y < 0 || vect.x >= WIN_WIDTH || vect.y >= WIN_HEIGHT)
				px_to_img(&env->minimap, x, y, 0);
			else
			{
				env->minimap.data[x * 4 + y * 4 * MAP_WIDTH] = img->data[(int)vect.x * 4 + (int)vect.y * 4 * WIN_WIDTH];
				env->minimap.data[(x * 4 + y * 4 * MAP_WIDTH) + 1] = img->data[((int)vect.x * 4 + (int)vect.y * 4 * WIN_WIDTH) + 1];
				env->minimap.data[(x * 4 + y * 4 * MAP_WIDTH) + 2] = img->data[((int)vect.x * 4 + (int)vect.y * 4 * WIN_WIDTH) + 2];
				env->minimap.data[(x * 4 + y * 4 * MAP_WIDTH) + 3] = img->data[((int)vect.x * 4 + (int)vect.y * 4 * WIN_WIDTH) + 3];
			}
			if (x == 0 || y == 0 || x == MAP_WIDTH - 1 || y == MAP_HEIGHT - 1)
				px_to_img(&env->minimap, x, y, 0xFFFFFF);
		}
	}
}

void						render(t_doom *doom)
{
	bzero(doom->img.data, doom->img.width * doom->img.height * 4);
	playermove(doom);
	ft_printmap(doom, &doom->img);
	ft_printplayer(doom, &doom->img);
	ft_make_minimap(doom, &doom->img);
	mlx_put_image_to_window(doom->mlx ,doom->window, doom->img.ptr, 0, 0);
	mlx_put_image_to_window(doom->mlx, doom->window, doom->minimap.ptr, 300, 300);
	//	printf("Render\n");
}
