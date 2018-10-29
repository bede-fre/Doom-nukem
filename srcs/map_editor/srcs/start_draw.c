/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 14:23:06 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	start_draw(t_env *env)
{
	t_draw draw;
	t_draw draw2;
	t_point p;

	SDL_RenderClear(env->renderer);
	draw = init_draw(env);
	draw2 = init_draw(env);
	make_grid(env, &draw);
	p.x = 60;
	p.y = 60;
	circle(draw.surface, p, 10, WHITE_T);
	uninit_draw(&draw, env);
	SDL_RenderPresent(env->renderer);
}
