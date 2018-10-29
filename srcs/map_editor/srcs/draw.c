/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:34:16 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 14:28:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE LA SURFACE
*/

t_draw	init_draw(t_env *env)
{
	t_draw	draw;

	if (!(draw.surface = SDL_CreateRGBSurface(0, WIN_WIDTH, WIN_HEIGHT, 32,
		0xFF, 0xFF00, 0xFF0000, 0xFF000000)))
		clear(env, &draw, SDL_GetError(), 4);
	return (draw);
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
