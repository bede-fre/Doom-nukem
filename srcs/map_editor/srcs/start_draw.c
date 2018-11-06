/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/06 10:09:29 by lguiller         ###   ########.fr       */
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
		if (current)
			line(surface, grid_to_wind(env, prev->p),
				grid_to_wind(env, current->p), GREEN);
		tmp_s = tmp_s->next;
	}
}

/*
** LANCEMENT DES FONCTIONS D'EDITION DE SURFACE
*/

void	start_draw(t_env *env)
{
	SDL_Surface *surface;

	SDL_RenderClear(env->renderer);
	surface = init_surface(env);
	make_grid(env, surface);
	print_map(env, surface);
	circle(surface, grid_to_wind(env, env->mouse), env->grid.scale / 2,
		LIGHT_GREY);
	create_texture(surface, env);
	SDL_RenderPresent(env->renderer);
}
