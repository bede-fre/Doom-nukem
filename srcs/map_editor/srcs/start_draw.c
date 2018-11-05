/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/05 14:55:56 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** AFFICHAGE DES MURS
*/

void	print_map(t_env *env, SDL_Surface *surface)
{
	t_sector	*tmp_s;
	t_vertex	*current;
	t_vertex	*prev;

	tmp_s = env->sector;
	while (tmp_s)
	{
		current = (tmp_s->vertex) ? tmp_s->vertex->next : NULL;
		prev = tmp_s->vertex;
		while (current && current != tmp_s->vertex)
		{
			if (current)
				line(surface, grid_to_wind(env, prev->p),
					grid_to_wind(env, current->p), GREEN);
			prev = current;
			current = current->next;
		}
		tmp_s = tmp_s->next;
	}
}

/*
** LANCEMENT DES FONCTIONS D'EDITION DE SURFACE
*/

void	start_draw(t_env *env)
{
	t_draw			draw;

	SDL_RenderClear(env->renderer);
	draw = init_draw(env);
	make_grid(env, &draw);
	print_map(env, draw.surface);
	circle(draw.surface, grid_to_wind(env, env->mouse), env->grid.scale / 2,
		LIGHT_GREY);
	uninit_draw(&draw, env);
	SDL_RenderPresent(env->renderer);
}
