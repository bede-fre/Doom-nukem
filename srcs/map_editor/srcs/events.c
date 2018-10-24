/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/24 16:39:58 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** ATTRIBITION D'UN UN A L'INDEX CORRESPONDANT A LA TOUCHE APPUYE
*/

static void	key_press(SDL_Event event, t_env *env)
{
	int index;

	index = -1;
	while (++index < K_END)
		if (event.key.keysym.sym == env->bindings[index])
			env->keys[index] = 1;
}

/*
** ATTRIBITION D'UN ZERO A L'INDEX CORRESPONDANT A LA TOUCHE APPUYE
*/

static void	key_release(SDL_Event event, t_env *env)
{
	int index;

	index = -1;
	while (++index < K_END)
		if (event.key.keysym.sym == env->bindings[index])
			env->keys[index] = 0;
}

/*
** GESTION DES ACTIONS A EFFECTUER LORS D'UN EVENEMENT CLAVIER
*/

void		keyboard_events(t_env *env)
{
	if (env->keys[K_UP])
		env->grid.gap.y += env->grid.gap_scale;
	if (env->keys[K_DOWN])
		env->grid.gap.y -= env->grid.gap_scale;
	if (env->keys[K_LEFT])
		env->grid.gap.x += env->grid.gap_scale;
	if (env->keys[K_RIGHT])
		env->grid.gap.x -= env->grid.gap_scale;
	if (env->keys[K_ZOOMIN])
		env->grid.scale += 1;
	if (env->keys[K_ZOOMOUT])
		env->grid.scale -= (env->grid.scale > 1) ? 1 : 0;
	clear_window(env->renderer);
	make_grid(env);
	SDL_RenderPresent(env->renderer);
}

/*
** GESTION DE LA FERMETURE DE LA FENETRE ET EVENEMENT CLAVIER
*/

void		events(SDL_Event event, int *loop, t_env *env)
{
	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
		event.key.keysym.sym == SDLK_ESCAPE))
		*loop = 0;
	if (event.type == SDL_KEYDOWN)
		key_press(event, env);
	if (event.type == SDL_KEYUP)
		key_release(event, env);
}
