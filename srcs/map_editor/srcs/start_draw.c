/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/31 10:20:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** LANCEMENT DES FONCTIONS D'EDITION DE SURFACE
*/

void			start_draw(t_env *env)
{
	t_draw			draw;
	t_point			new_mouse;

	SDL_RenderClear(env->renderer);
	draw = init_draw(env);
	make_grid(env, &draw);
	new_mouse = grid_to_wind(env, env->mouse);
	circle(draw.surface, new_mouse, env->grid.scale / 2, LIGHT_GREY);
	uninit_draw(&draw, env);
	SDL_RenderPresent(env->renderer);
}
