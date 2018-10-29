/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:34:16 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 12:34:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	init_draw(t_draw *draw)
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

void	uninit_draw(t_draw *draw, t_env *env)
{
	draw->texture = SDL_CreateTextureFromSurface(env->renderer, draw->surface);
	SDL_FreeSurface(draw->surface);
	SDL_RenderCopy(env->renderer, draw->texture, NULL, NULL);
	SDL_DestroyTexture(draw->texture);
}

