/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/16 16:32:25 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		set_background(SDL_Surface *surface, Uint32 col)
{
	t_point p;

	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
			fill_px(surface, p.x, p.y, col);
	}
}

static void		print_texture(t_env *env)
{
	SDL_Rect rect;

	rect = create_rect(env->buttons[WOOD].rect.x + 2,
		env->buttons[WOOD].rect.y + 2, env->buttons[WOOD].rect.w - 3,
		env->buttons[WOOD].rect.h - 3);
	SDL_RenderCopy(env->renderer, env->buttons[WOOD].texture, NULL, &rect);
	rect = create_rect(env->buttons[METAL].rect.x + 2,
		env->buttons[METAL].rect.y + 2, env->buttons[METAL].rect.w - 3,
		env->buttons[METAL].rect.h - 3);
	SDL_RenderCopy(env->renderer, env->buttons[METAL].texture, NULL, &rect);
	rect = create_rect(env->buttons[STONE].rect.x + 2,
		env->buttons[STONE].rect.y + 2, env->buttons[STONE].rect.w - 3,
		env->buttons[STONE].rect.h - 3);
	SDL_RenderCopy(env->renderer, env->buttons[STONE].texture, NULL, &rect);
	rect = create_rect(env->buttons[ICE].rect.x + 2,
		env->buttons[ICE].rect.y + 2, env->buttons[ICE].rect.w - 3,
		env->buttons[ICE].rect.h - 3);
	SDL_RenderCopy(env->renderer, env->buttons[ICE].texture, NULL, &rect);
	rect = create_rect(env->buttons[B_ERASER].rect.x + 2,
		env->buttons[B_ERASER].rect.y + 2, env->buttons[B_ERASER].rect.w - 3,
		env->buttons[B_ERASER].rect.h - 3);
	SDL_RenderCopy(env->renderer, env->buttons[B_ERASER].texture, NULL, &rect);
}

/*
** LANCEMENT DES FONCTIONS D'EDITION DE SURFACE
*/

void			start_draw(t_env *env)
{
	SDL_Surface *surface;

	SDL_RenderClear(env->renderer);
	surface = init_surface(env);
	set_background(surface, WHITE);
	set_text(surface, env);
	make_grid(surface);
	print_map(surface, env->map);
	print_buttons(env, surface, env->object, env->colision);
	create_texture(surface, env);
	print_texture(env);
	SDL_RenderPresent(env->renderer);
}
