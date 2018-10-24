/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/24 12:11:58 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** GESTION DE LA FERMETURE DE LA FENETRE
*/

void	events(SDL_Event event, int *loop, t_env *env)
{
	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN
		&& event.key.keysym.sym == SDLK_ESCAPE))
		*loop = 0;
	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_UP)
			++env->grid.gap.y;
		if (event.key.keysym.sym == SDLK_DOWN)
			--env->grid.gap.y;
		if (event.key.keysym.sym == SDLK_LEFT)
			++env->grid.gap.x;
		if (event.key.keysym.sym == SDLK_RIGHT)
			--env->grid.gap.x;
		clear_window(env->renderer);
		make_grid(env);
		SDL_RenderPresent(env->renderer);
	}
}
