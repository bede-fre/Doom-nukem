/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 16:34:44 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	start_draw(t_env *env)
{
	t_draw	draw;
	t_draw	draw2;
	t_point	new_mouse;
	t_point	new_p1;
	t_point new_p2;

	SDL_RenderClear(env->renderer);
	draw = init_draw(env);
	draw2 = init_draw(env);
	make_grid(env, &draw);
	new_mouse.x = (env->mouse.x * env->grid.scale + env->grid.center.x + env->grid.gap.x);
	new_mouse.y = (env->mouse.y * env->grid.scale + env->grid.center.y + env->grid.gap.y);
	circle(draw.surface, new_mouse, 10, WHITE_T);
	if (env->t)
	{
		new_p1.x = (env->p1.x * env->grid.scale + env->grid.center.x + env->grid.gap.x);
		new_p1.y = (env->p1.y * env->grid.scale + env->grid.center.y + env->grid.gap.y);
		new_p2.x = (env->p2.x * env->grid.scale + env->grid.center.x + env->grid.gap.x);
		new_p2.y = (env->p2.y * env->grid.scale + env->grid.center.y + env->grid.gap.y);
		line(draw.surface, new_p1, new_p2, GREEN);
	}
	uninit_draw(&draw, env);
	SDL_RenderPresent(env->renderer);
}
