/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:34:16 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 13:04:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE LA SURFACE
*/

void	init_draw(t_draw *draw, t_env *env)
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
	if (!(draw->surface = SDL_CreateRGBSurface(0, WIN_WIDTH, WIN_HEIGHT, 32,
		rmask, gmask, bmask, amask)))
		clear(env, draw, SDL_GetError(), 4);
}

/*
** INITIALISATION DE LA TEXTURE VIA LA SURFACE, COPY DE LA SURFACE DANS
** LE RENDERER ET DESTRUCTION DE LA TEXTURE ET DE LA SURFACE
*/

void	uninit_draw(t_draw *draw, t_env *env)
{
	if (!(draw->texture = SDL_CreateTextureFromSurface(env->renderer,
		draw->surface)))
		clear(env, draw, SDL_GetError(), 5);
	SDL_FreeSurface(draw->surface);
	SDL_RenderCopy(env->renderer, draw->texture, NULL, NULL);
	SDL_DestroyTexture(draw->texture);
}
