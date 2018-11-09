/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/05 16:18:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** ENREGISTREMENT DE LA GRILLE DANS LA SURFACE
*/

void		make_grid(t_env *env, SDL_Surface *surface)
{
	t_point			p;
	t_point			new_gap;

	new_gap.x = env->grid.center.x + env->grid.gap.x;
	new_gap.y = env->grid.center.y + env->grid.gap.y;
	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
		{
			if (abs(p.x - new_gap.x) % env->grid.scale == 0 ||
				abs(p.y - new_gap.y) % (env->grid.scale) == 0)
				fill_px(surface, p.x, p.y, GREY);
			if (p.x == new_gap.x || p.y == new_gap.y)
				fill_px(surface, p.x, p.y, RED);
		}
	}
}
