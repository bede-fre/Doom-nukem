/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 11:53:33 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	init_draw(t_draw *draw)
{
	Uint32	rmask;
	Uint32	gmask;
	Uint32	bmask;
	Uint32	amask;

	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		rmask = 0xFF000000;
		gmask = 0xFF0000;
		bmask = 0xFF00;
		amask = 0xFF;
	}
	else
	{
		rmask = 0xFF;
		gmask = 0xFF00;
		bmask = 0xFF0000;
		amask = 0xFF000000;
	}
	draw->surface = SDL_CreateRGBSurface(0, WIN_WIDTH, WIN_HEIGHT, 32,
		rmask, gmask, bmask, amask);
}

static void	uninit_draw(t_draw *draw, t_env *env)
{
	draw->texture = SDL_CreateTextureFromSurface(env->renderer, draw->surface);
	SDL_FreeSurface(draw->surface);
	SDL_RenderCopy(env->renderer, draw->texture, NULL, NULL);
	SDL_DestroyTexture(draw->texture);
}

void		make_grid(t_env *env)
{
	t_point			p;
	t_point			new_gap;
	t_draw			draw;
	Uint32			*tmp;

	init_draw(&draw);
	new_gap.x = env->grid.center.x + env->grid.gap.x;
	new_gap.y = env->grid.center.y + env->grid.gap.y;
	tmp = (Uint32*)draw.surface->pixels;
	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
		{
			if (abs(p.x - new_gap.x) % env->grid.scale == 0 ||
				abs(p.y - new_gap.y) % (env->grid.scale) == 0)
				*(tmp + p.x + p.y * WIN_WIDTH) = GREY;
			if (p.x == new_gap.x || p.y == new_gap.y)
				*(tmp + p.x + p.y * WIN_WIDTH) = RED;
		}
	}
	uninit_draw(&draw, env);
}
