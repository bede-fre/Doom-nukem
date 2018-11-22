/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/22 10:36:58 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	init_sounds(t_env *env)
{
	if ((env->sounds.wood = Mix_LoadMUS(S_WOOD)) == NULL)
		ft_puterror(Mix_GetError());
	if ((env->sounds.metal = Mix_LoadMUS(S_METAL)) == NULL)
		ft_puterror(Mix_GetError());
	if ((env->sounds.stone = Mix_LoadMUS(S_STONE)) == NULL)
		ft_puterror(Mix_GetError());
	if ((env->sounds.ice = Mix_LoadMUS(S_ICE)) == NULL)
		ft_puterror(Mix_GetError());
	if ((env->sounds.tp_start = Mix_LoadMUS(S_TP_S)) == NULL)
		ft_puterror(Mix_GetError());
	if ((env->sounds.tp_exit = Mix_LoadMUS(S_TP_E)) == NULL)
		ft_puterror(Mix_GetError());
	if ((env->sounds.erase = Mix_LoadMUS(S_ERASER)) == NULL)
		ft_puterror(Mix_GetError());
	if ((env->sounds.error = Mix_LoadMUS(S_ERROR)) == NULL)
		ft_puterror(Mix_GetError());
}

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
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		clear(env, Mix_GetError(), 20);
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
	env->bindings[K_LEAKS] = (int)SDLK_SPACE;
	env->bindings[B_LEFT] = (int)SDL_BUTTON_LEFT;
	env->bindings[B_RIGHT] = (int)SDL_BUTTON_RIGHT;
}

static void	init_textures(t_env *env)
{
	SDL_Surface *s;

	s = IMG_Load(TEXT_A);
	if (!(env->text.t_a = SDL_CreateTextureFromSurface(env->renderer, s)))
		clear(env, SDL_GetError(), 12);
	SDL_FreeSurface(s);
	s = IMG_Load(TEXT_B);
	if (!(env->text.t_b = SDL_CreateTextureFromSurface(env->renderer, s)))
		clear(env, SDL_GetError(), 13);
	SDL_FreeSurface(s);
	s = IMG_Load(TEXT_C);
	if (!(env->text.t_c = SDL_CreateTextureFromSurface(env->renderer, s)))
		clear(env, SDL_GetError(), 14);
	SDL_FreeSurface(s);
	s = IMG_Load(TEXT_D);
	if (!(env->text.t_d = SDL_CreateTextureFromSurface(env->renderer, s)))
		clear(env, SDL_GetError(), 15);
	s = IMG_Load(ERASER);
	if (!(env->text.eraser = SDL_CreateTextureFromSurface(env->renderer, s)))
		clear(env, SDL_GetError(), 16);
	s = IMG_Load(TEXT_DOOR);
	if (!(env->text.door = SDL_CreateTextureFromSurface(env->renderer, s)))
		clear(env, SDL_GetError(), 17);
	SDL_FreeSurface(s);
}

void		init(t_env *env, char *file_name)
{
	init_sdl(env);
	read_file(file_name, &env->map);
	init_bindings(env);
	init_textures(env);
	init_button(env);
	init_sounds(env);
	env->file_name = (char*)ft_memalloc(sizeof(char) *
		(ft_strlen(file_name) + 1));
	env->file_name = ft_strcpy(env->file_name, file_name);
	env->object = T_A;
	env->colision = TRUE;
}
