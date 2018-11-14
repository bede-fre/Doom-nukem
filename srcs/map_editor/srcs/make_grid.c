/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/12 11:23:45 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** ENREGISTREMENT DE LA GRILLE DANS LA SURFACE
*/

void		make_grid(SDL_Surface *surface)
{
	t_point	p;

	p.y = -1;
	while (++p.y <= MAP_HEIGHT)
	{
		p.x = -1;
		while (++p.x <= MAP_WIDTH)
			fill_px(surface, p.x * SCALE + GAP, p.y * SCALE + GAP, BLACK);
	}
}
