/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/16 16:31:44 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE LA SDL
*/

static void	init_sdl(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		clear(env, SDL_GetError(), 1);
	if (TTF_Init() == -1)
		clear(env, TTF_GetError(), 16);
	env->font = TTF_OpenFont(FONT, SCALE);
	if (!(env->window = SDL_CreateWindow("GAME EDITOR", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, 0)))
		clear(env, SDL_GetError(), 2);
	if (!(env->renderer = SDL_CreateRenderer(env->window, -1,
		SDL_RENDERER_ACCELERATED)))
		clear(env, SDL_GetError(), 3);
}

/*
** INITIALISATION DU TABLEAU DE TOUCHE
*/

static void	init_bindings(t_env *env)
{
	env->keys = (int*)ft_memalloc(sizeof(int) * K_END + 1);
	env->bindings = (int*)ft_memalloc(sizeof(int) * K_END + 1);
	env->bindings[K_RESET] = (int)SDLK_SPACE;
	env->bindings[K_RENDER] = (int)SDLK_RETURN;
	env->bindings[K_QUIT] = (int)SDLK_ESCAPE;
	env->bindings[B_LEFT] = (int)SDL_BUTTON_LEFT;
	env->bindings[B_RIGHT] = (int)SDL_BUTTON_RIGHT;
}

static void	init_textures(t_env *env)
{
	SDL_Surface *surface;

	surface = IMG_Load(TEXT_A);
	if (!(env->text.t_a = SDL_CreateTextureFromSurface(env->renderer, surface)))
		clear(env, SDL_GetError(), 12);
	SDL_FreeSurface(surface);
	surface = IMG_Load(TEXT_B);
	if (!(env->text.t_b = SDL_CreateTextureFromSurface(env->renderer, surface)))
		clear(env, SDL_GetError(), 13);
	SDL_FreeSurface(surface);
	surface = IMG_Load(TEXT_C);
	if (!(env->text.t_c = SDL_CreateTextureFromSurface(env->renderer, surface)))
		clear(env, SDL_GetError(), 14);
	SDL_FreeSurface(surface);
	surface = IMG_Load(TEXT_D);
	if (!(env->text.t_d = SDL_CreateTextureFromSurface(env->renderer, surface)))
		clear(env, SDL_GetError(), 15);
	surface = IMG_Load(ERASER);
	if (!(env->text.eraser =
		SDL_CreateTextureFromSurface(env->renderer, surface)))
		clear(env, SDL_GetError(), 16);
	SDL_FreeSurface(surface);
}

void		init(t_env *env, char *file_name)
{
	init_sdl(env);
	read_file(file_name, &env->map);
	init_bindings(env);
	init_textures(env);
	init_button(env);
	env->file_name = (char*)ft_memalloc(sizeof(char) *
		(ft_strlen(file_name) + 1));
	env->file_name = ft_strcpy(env->file_name, file_name);
	env->object = T_A;
	env->colision = TRUE;
}
