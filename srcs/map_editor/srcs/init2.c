/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:47:28 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/05 15:41:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE LA SURFACE
*/

SDL_Surface	*init_surface(t_env *env)
{
	SDL_Surface *surface;

	if (!(surface = SDL_CreateRGBSurface(0, WIN_WIDTH, WIN_HEIGHT, 32,
		0xFF, 0xFF00, 0xFF0000, 0xFF000000)))
	{
		SDL_FreeSurface(surface);
		clear(env, SDL_GetError(), 4);
	}
	return (surface);
}

/*
** INITIALISATION DE LA TEXTURE VIA LA SURFACE, COPY DE LA SURFACE DANS
** LE RENDERER ET DESTRUCTION DE LA TEXTURE ET DE LA SURFACE
*/

void		create_texture(SDL_Surface *surface, t_env *env)
{
	SDL_Texture *texture;

	if (!(texture = SDL_CreateTextureFromSurface(env->renderer, surface)))
	{
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
		clear(env, SDL_GetError(), 5);
	}
	SDL_FreeSurface(surface);
	SDL_RenderCopy(env->renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
}
