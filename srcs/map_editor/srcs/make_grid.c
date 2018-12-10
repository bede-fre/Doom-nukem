/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 17:17:04 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** ENREGISTREMENT DE LA GRILLE DANS LA SURFACE
*/

void		make_grid(SDL_Surface *surface)
{
	t_point	p;

	p.y = -3;
	while (++p.y < map_to_win(MAP_HEIGHT - 1) + 3)
	{
		p.x = -3;
		while (++p.x < map_to_win(MAP_WIDTH - 1) + 3)
			if (p.x <= 0 || p.y <= 0 || p.x >= map_to_win(MAP_WIDTH - 1) || p.y >= map_to_win(MAP_HEIGHT - 1))
			fill_px(surface, p.x + GAP, p.y + GAP, BLACK);
	}
	p.y = 0;
	while (++p.y < map_to_win(MAP_HEIGHT - 1))
	{
		p.x = 0;
		while (++p.x < map_to_win(MAP_WIDTH - 1))
			fill_px(surface, p.x + GAP, p.y + GAP, LIGHT_GREY);
	}
	p.y = 0;
	while (++p.y <= MAP_HEIGHT)
	{
		p.x = 0;
		while (++p.x <= MAP_WIDTH)
			fill_px(surface, p.x * SCALE + GAP, p.y * SCALE + GAP, BLACK);
	}
}
