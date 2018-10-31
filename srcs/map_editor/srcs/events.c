/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/31 13:40:00 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** ATTRIBITION D'UN UN A L'INDEX CORRESPONDANT A LA TOUCHE APPUYE
*/

static void	press(SDL_Event event, t_env *env)
{
	int index;

	index = -1;
	while (++index < K_END)
		if (event.key.keysym.sym == env->bindings[index] ||
			event.button.button == env->bindings[index])
			env->keys[index] = 1;
}

/*
** ATTRIBITION D'UN ZERO A L'INDEX CORRESPONDANT A LA TOUCHE APPUYE
*/

static void	release(SDL_Event event, t_env *env)
{
	int index;

	index = -1;
	while (++index < K_END)
		if (event.key.keysym.sym == env->bindings[index] ||
			event.button.button == env->bindings[index])
			env->keys[index] = 0;
}

/*
** CONVERSION DES COORDONNEES DE LA SOURIS RELATIVES A LA FENETRE EN COORDONNEES
** RELATIVES A LA GRILLE
*/

static void	mouse_motion(SDL_Event event, t_env *env)
{
	env->mouse = wind_to_grid(env, ft_pointdef(event.motion.x, event.motion.y));
}

/*
** NE SERT A RIEN POUR L'INSTANT
*/

static void	mouse_button(SDL_Event event, t_env *env)
{
	(void)event;
	(void)env;
}

/*
** GESTION DE LA FERMETURE DE LA FENETRE ET EVENEMENT CLAVIER
*/

void		events(SDL_Event event, int *loop, t_env *env)
{
	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
		event.key.keysym.sym == SDLK_ESCAPE))
		*loop = 0;
	if (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN)
		press(event, env);
	if (event.type == SDL_KEYUP || event.type == SDL_MOUSEBUTTONUP)
		release(event, env);
	if (event.type == SDL_MOUSEMOTION)
		mouse_motion(event, env);
	if (event.type == SDL_MOUSEBUTTONDOWN)
		mouse_button(event, env);
}
