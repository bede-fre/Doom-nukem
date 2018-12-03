/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/03 13:43:08 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		set_background(SDL_Surface *surface)
{
	t_point			p;
	const int		d = 2;
	const t_point	px = {map_to_win(33), map_to_win(50)};
	const t_point	py = {map_to_win(0), map_to_win(32)};

	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
			fill_px(surface, p.x, p.y, WHITE);
	}
	p.y = py.x;
	while (++p.y < py.y)
	{
		p.x = px.x;
		while (++p.x < px.y)
		{
			if (p.x <= (px.x + d) || p.x >= (px.y - d) || p.y <= (py.x + d)
				|| p.y >= (py.y - d))
				fill_px(surface, p.x, p.y, BLACK);
			else
				fill_px(surface, p.x, p.y, LIGHT_GREY);
		}
	}
}

static void		print_texture(t_env *env)
{
	SDL_Rect	rect;
	int			i;

	i = -1;
	while (++i <= BARREL)
	{
		rect = create_rect(env->buttons[i].rect.x + 2,
			env->buttons[i].rect.y + 2, env->buttons[i].rect.w - 3,
			env->buttons[i].rect.h - 3);
		SDL_RenderCopy(env->renderer, env->buttons[i].texture, NULL, &rect);
	}
	rect = create_rect(env->buttons[B_ERASER].rect.x + 2,
		env->buttons[B_ERASER].rect.y + 2, env->buttons[B_ERASER].rect.w - 3,
		env->buttons[B_ERASER].rect.h - 3);
	SDL_RenderCopy(env->renderer, env->buttons[B_ERASER].texture, NULL, &rect);
	rect = create_rect(env->buttons[B_DOOR].rect.x + 2,
		env->buttons[B_DOOR].rect.y + 2, env->buttons[B_DOOR].rect.w - 3,
		env->buttons[B_DOOR].rect.h - 3);
	SDL_RenderCopy(env->renderer, env->buttons[B_DOOR].texture, NULL, &rect);
	rect = create_rect(env->buttons[B_SOUND].rect.x,
		env->buttons[B_SOUND].rect.y, env->buttons[B_SOUND].rect.w,
		env->buttons[B_SOUND].rect.h);
	SDL_RenderCopy(env->renderer, env->buttons[(env->sound == 1) ?
		B_SOUND : B_MUTE].texture, NULL, &rect);
}

/*
** LANCEMENT DES FONCTIONS D'EDITION DE SURFACE
*/

void			start_draw(t_env *env)
{
	SDL_Surface *surface;

	SDL_RenderClear(env->renderer);
	surface = init_surface(env);
	set_background(surface);
	make_grid(surface);
	print_map(surface, env->map);
	print_buttons(env, surface, env->object, env->colision);
	set_text(surface, env);
	print_view(surface, env);
	print_texture(env);
	SDL_RenderPresent(env->renderer);
}
