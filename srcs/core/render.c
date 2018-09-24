/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:17:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/24 17:34:55 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int							ft_printplayer(t_doom *env, t_img *img)
{
	t_vec					playerpos;

	playerpos = ft_vecscale(env->player.pos, 100);
	px_to_img(img, playerpos.x, playerpos.y, 0xffff00);
	return (1);
}

int							ft_printroom(t_doom *env, t_img *img)
{
	return (1);
}

void						render(t_doom *doom)
{
//	ft_bzero(doom->img->data, doom->img->width * doom->img->height * 4);
	playermove(doom);
	ft_putline(ft_vecdef(0, 200, 0), ft_vecdef(0, 0, 0), &doom->img, 0xffffff);
	ft_printroom(doom, &doom->img);
	ft_printplayer(doom, &doom->img);
	mlx_put_image_to_window(doom->mlx ,doom->window, doom->img.ptr, 0, 0);
//	printf("Render\n");
}
