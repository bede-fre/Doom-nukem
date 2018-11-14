/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/12 11:22:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	mouse_motion(SDL_Event event, t_env *env)
{
	env->mouse.x = event.motion.x;
	env->mouse.y = event.motion.y;
	refresh_events(env);
}

void		events(SDL_Event event, int *loop, t_env *env)
{
	if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN &&
		event.key.keysym.sym == SDLK_ESCAPE))
		*loop = 0;
	if (event.type == SDL_KEYDOWN)
		key_press(event, env);
	if (event.type == SDL_KEYUP)
		key_release(event, env);
	if (event.type == SDL_MOUSEBUTTONDOWN)
		button_press(event, env);
	if (event.type == SDL_MOUSEBUTTONUP)
		button_release(event, env);
	if (event.type == SDL_MOUSEMOTION)
		mouse_motion(event, env);
}
