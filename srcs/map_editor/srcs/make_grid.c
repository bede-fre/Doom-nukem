/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/24 15:30:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	make_grid(t_env *env)
{
	t_point			p;
	const SDL_Color	white = {200, 200, 200, 0};
	const SDL_Color	red = {200, 0, 0, 0};
	t_point			new_gap;

	new_gap.x = env->grid.center.x + env->grid.gap.x;
	new_gap.y = env->grid.center.y + env->grid.gap.y;
	p.y = -1;
	while (++p.y <= WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x <= WIN_WIDTH)
		{
			if (abs(p.x - new_gap.x) % env->grid.scale == 0 ||
				abs(p.y - new_gap.y) % env->grid.scale == 0)
				set_pixel(env->renderer, p.x, p.y, white);
			if (p.x == new_gap.x || p.y == new_gap.y)
				set_pixel(env->renderer, p.x, p.y, red);
		}
	}
}
