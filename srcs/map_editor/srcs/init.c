/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/25 10:39:30 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE LA SDL
*/

static void	init_sdl(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error((char*)SDL_GetError(), 1, ft_puterror);
	if (!(env->window = SDL_CreateWindow("GAME EDITOR", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL)))
		ft_error((char*)SDL_GetError(), 2, ft_puterror);
	if (!(env->renderer = SDL_CreateRenderer(env->window, -1, 0)))
		ft_error((char*)SDL_GetError(), 3, ft_puterror);
}

/*
** INITIALISATION DE LA GRILLE
*/

static void	init_grid(t_env *env)
{
	env->grid.scale = 10;
	env->grid.gap_scale = env->grid.scale;
	env->grid.center.x = WIN_WIDTH / 2;
	env->grid.center.y = WIN_HEIGHT / 2;
	env->grid.gap.x = 0;
	env->grid.gap.y = 0;
}

/*
** INITIALISATION DU TABLEAU DE TOUCHE
*/

static void	init_bindings(t_env *env)
{
	env->keys = (int*)ft_memalloc(sizeof(int) * K_END + 1);
	env->bindings = (int*)ft_memalloc(sizeof(int) * K_END + 1);
	env->bindings[K_UP] = SDLK_UP;
	env->bindings[K_DOWN] = SDLK_DOWN;
	env->bindings[K_LEFT] = SDLK_LEFT;
	env->bindings[K_RIGHT] = SDLK_RIGHT;
	env->bindings[K_ZOOMIN] = SDLK_EQUALS;
	env->bindings[K_ZOOMOUT] = SDLK_MINUS;
	env->bindings[K_RESET] = SDLK_SPACE;
	env->bindings[K_QUIT] = SDLK_ESCAPE;
}

void		init(t_env *env)
{
	init_sdl(env);
	init_grid(env);
	init_bindings(env);
}
