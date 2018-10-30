/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/30 13:57:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** TRANSPOSITION DES COORDONNEES DU POINT P RELATIVE A LA POSITION DE LA GRILLE
** EN POSITION RELATIVE A LA FENETRE
*/

static t_point	transposition(t_env *env, t_point p)
{
	t_point	new_p;
	t_point	transpos;

	transpos = ft_pointdef(env->grid.center.x + env->grid.gap.x,
		env->grid.center.y + env->grid.gap.y);
	new_p.x = p.x * env->grid.scale + transpos.x;
	new_p.y = p.y * env->grid.scale + transpos.y;
	return (new_p);
}

/*
** LANCEMENT DES FONCTIONS D'EDITION DE SURFACE
*/

void			start_draw(t_env *env)
{
	t_draw			draw;
	t_point			new_mouse;
	t_point			new_p1;
	t_point			new_p2;

	SDL_RenderClear(env->renderer);
	draw = init_draw(env);
	make_grid(env, &draw);
	new_mouse = transposition(env, env->mouse);
	circle(draw.surface, new_mouse, env->grid.scale / 2, LIGHT_GREY);
	if (env->t)
	{
		new_p1 = transposition(env, env->p1);
		new_p2 = transposition(env, env->p2);
		line(draw.surface, new_p1, new_p2, GREEN);
	}
	uninit_draw(&draw, env);
	SDL_RenderPresent(env->renderer);
}
