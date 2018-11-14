/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/12 10:34:24 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** ATTRIBITION D'UN UN A L'INDEX CORRESPONDANT A LA TOUCHE APPUYE
*/

void	key_press(SDL_Event event, t_env *env)
{
	int index;

	index = -1;
	while (++index < K_END)
		if (event.key.keysym.sym == env->bindings[index])
			env->keys[index] = 1;
	refresh_events(env);
}

/*
** ATTRIBITION D'UN ZERO A L'INDEX CORRESPONDANT A LA TOUCHE RELACHE
*/

void	key_release(SDL_Event event, t_env *env)
{
	int index;

	index = -1;
	while (++index < K_END)
		if (event.key.keysym.sym == env->bindings[index])
			env->keys[index] = 0;
}

/*
** ATTRIBITION D'UN UN A L'INDEX CORRESPONDANT AU BUTTON APPUYE
*/

void	button_press(SDL_Event event, t_env *env)
{
	int index;

	index = -1;
	while (++index < K_END)
		if (event.button.button == env->bindings[index])
			env->keys[index] = 1;
	refresh_events(env);
}

/*
** ATTRIBITION D'UN ZERO A L'INDEX CORRESPONDANT AU BUTTON RELACHE
*/

void	button_release(SDL_Event event, t_env *env)
{
	int index;

	index = -1;
	while (++index < K_END)
		if (event.button.button == env->bindings[index])
			env->keys[index] = 0;
}
