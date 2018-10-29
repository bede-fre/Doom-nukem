/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 12:58:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		make_grid(t_env *env)
{
	t_point			p;
	t_point			new_gap;
	t_draw			draw;
	Uint32			*tmp;

	init_draw(&draw, env);
	new_gap.x = env->grid.center.x + env->grid.gap.x;
	new_gap.y = env->grid.center.y + env->grid.gap.y;
	tmp = (Uint32*)draw.surface->pixels;
	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
		{
			if (abs(p.x - new_gap.x) % env->grid.scale == 0 ||
				abs(p.y - new_gap.y) % (env->grid.scale) == 0)
				*(tmp + p.x + p.y * WIN_WIDTH) = GREY;
			if (p.x == new_gap.x || p.y == new_gap.y)
				*(tmp + p.x + p.y * WIN_WIDTH) = RED;
		}
	}
	uninit_draw(&draw, env);
}
