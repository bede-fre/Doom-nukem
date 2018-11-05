/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/05 15:43:00 by lguiller         ###   ########.fr       */
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
	if (!(env->window = SDL_CreateWindow("GAME EDITOR", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL)))
		clear(env, SDL_GetError(), 2);
	if (!(env->renderer = SDL_CreateRenderer(env->window, -1,
		SDL_RENDERER_ACCELERATED)))
		clear(env, SDL_GetError(), 3);
}

/*
** INITIALISATION DE LA GRILLE
*/

static void	init_grid(t_env *env)
{
	env->grid.scale = 20;
	env->grid.center.x = WIN_WIDTH / 2;
	env->grid.center.y = WIN_HEIGHT / 2;
	env->grid.gap.x = 0;
	env->grid.gap.y = 0;
	env->actual_sec = 0;
	env->actual_vert = 0;
	env->sector = (t_sector*)ft_memalloc(sizeof(t_sector));
	env->sector->num = 0;
	env->sector->next = NULL;
	env->sector->vertex = NULL;
}

/*
** INITIALISATION DU TABLEAU DE TOUCHE
*/

static void	init_bindings(t_env *env)
{
	env->keys = (int*)ft_memalloc(sizeof(int) * K_END + 1);
	env->bindings = (int*)ft_memalloc(sizeof(int) * K_END + 1);
	env->bindings[K_UP] = (int)SDLK_UP;
	env->bindings[K_DOWN] = (int)SDLK_DOWN;
	env->bindings[K_LEFT] = (int)SDLK_LEFT;
	env->bindings[K_RIGHT] = (int)SDLK_RIGHT;
	env->bindings[K_ZOOMIN] = (int)SDLK_EQUALS;
	env->bindings[K_ZOOMOUT] = (int)SDLK_MINUS;
	env->bindings[K_RESET] = (int)SDLK_SPACE;
	env->bindings[B_LEFT] = (int)SDL_BUTTON_LEFT;
	env->bindings[K_QUIT] = (int)SDLK_ESCAPE;
}

void		init(t_env *env)
{
	init_sdl(env);
	init_grid(env);
	init_bindings(env);
}
