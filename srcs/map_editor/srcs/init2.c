/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:47:28 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/07 14:11:06 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE LA SURFACE
*/

SDL_Surface	*init_surface(t_env *env, int w, int h)
{
	SDL_Surface *surface;

	if (!(surface = SDL_CreateRGBSurface(0, w, h, 32,
		0xFF000000, 0xFF0000, 0xFF00, 0xFF)))
	{
		SDL_FreeSurface(surface);
		clear(env, SDL_GetError(), 4);
	}
	return (surface);
}

SDL_Texture	*create_texture(SDL_Surface *surface, t_env *env)
{
	SDL_Texture *texture;

	if (!(texture = SDL_CreateTextureFromSurface(env->renderer, surface)))
	{
		SDL_FreeSurface(surface);
		clear(env, SDL_GetError(), 12);
	}
	SDL_FreeSurface(surface);
	return (texture);
}

/*
** INITIALISATION DE LA TEXTURE VIA LA SURFACE, COPY DE LA SURFACE DANS
** LE RENDERER ET DESTRUCTION DE LA TEXTURE ET DE LA SURFACE
*/

void		print_view(SDL_Surface *surface, t_env *env)
{
	SDL_Texture *texture;

	if (!(texture = SDL_CreateTextureFromSurface(env->renderer, surface)))
	{
		SDL_FreeSurface(surface);
		clear(env, SDL_GetError(), 5);
	}
	SDL_FreeSurface(surface);
	SDL_RenderCopy(env->renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
}
