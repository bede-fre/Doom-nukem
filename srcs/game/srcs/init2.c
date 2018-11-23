/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:56:49 by cmace             #+#    #+#             */
/*   Updated: 2018/11/23 15:09:00 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_init_sdl(t_all *all)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(0);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		exit(0);
	init_sounds(all);
}

void	init_sounds(t_all *all)
{
	if ((all->musics.musics = Mix_LoadMUS(M_WOAH)) == NULL)
		ft_puterror(Mix_GetError());
	if ((all->sounds.opendoor = Mix_LoadWAV(S_OPENDOOR)) == NULL)
		ft_puterror(Mix_GetError());
	if ((all->sounds.teleport = Mix_LoadWAV(S_TELEPORT)) == NULL)
		ft_puterror(Mix_GetError());
}

static int	find_src_pixel_col(t_img *img, int x, int y)
{
	const int px = x * 4 + y * img->sl;

	return (ft_rgba(img->data[px + 2], img->data[px + 1], img->data[px],
			img->data[px + 3]));
}

void		scale_img(t_img *dst, t_img *src)
{
	double	incx;
	double	incy;
	t_point	p;

	incx = (double)src->width / (double)dst->width;
	incy = (double)src->height / (double)dst->height;
	p.y = -1;
	while (++p.y < dst->height)
	{
		p.x = -1;
		while (++p.x < dst->width)
			ft_fill_pixel(dst, p.x, p.y, find_src_pixel_col(src,
			(int)((double)p.x * incx), (int)((double)p.y * incy)));
	}
}
