/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 16:25:54 by lguiller         ###   ########.fr       */
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

static void	mouse_motion(SDL_Event event, t_env *env)
{
	t_point	center;
	t_point	mouser;
	int		upper;
	int		under;

	center.x = env->grid.center.x + env->grid.gap.x;
	center.y = env->grid.center.y + env->grid.gap.y;
	mouser.x = event.motion.x - center.x;
	mouser.y = event.motion.y - center.y;
	upper = ft_roundmsup(mouser.x, env->grid.scale);
	under = ft_roundminf(mouser.x, env->grid.scale);
	env->mouse.x = (upper - mouser.x < mouser.x - under) ? upper : under;
	upper = ft_roundmsup(mouser.y, env->grid.scale);
	under = ft_roundminf(mouser.y, env->grid.scale);
	env->mouse.y = (upper - mouser.y < mouser.y - under) ? upper : under;
	env->mouse.x = (int)((double)env->mouse.x / (double)env->grid.scale);
	env->mouse.y = (int)((double)env->mouse.y / (double)env->grid.scale);
}

static void	mouse_button(SDL_Event event, t_env *env)
{
	static int		i;

	(void)event;
	if (i == 0)
	{
		env->t = 0;
		env->p1.x = env->mouse.x;
		env->p1.y = env->mouse.y;
		++i;
	}
	else if (i == 1)
	{
		env->p2.x = env->mouse.x;
		env->p2.y = env->mouse.y;
		env->t = 1;
		i = 0;
	}
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
	if (event.type == SDL_MOUSEMOTION)
		mouse_motion(event, env);
	if (event.type == SDL_MOUSEBUTTONDOWN)
		mouse_button(event, env);
}
