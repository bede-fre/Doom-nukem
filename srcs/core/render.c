/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/24 20:56:12 by toliver          ###   ########.fr       */
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

void						render(t_doom *doom)
{
	bzero(doom->img.data, doom->img.width * doom->img.height * 4);
	playermove(doom);
	ft_printmap(doom, &doom->img);
	ft_printplayer(doom, &doom->img);
	mlx_put_image_to_window(doom->mlx ,doom->window, doom->img.ptr, 0, 0);
//	printf("Render\n");
}
