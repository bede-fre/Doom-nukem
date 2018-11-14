/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:07:26 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/12 11:24:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** AJOUT D"UNE NOUVELLE COULEUR DANS SURFACE->PIXELS A LA POSITION X Y
*/

void	fill_px(SDL_Surface *surface, int x, int y, Uint32 col)
{
	if (x >= 0 && x < surface->w && y >= 0 && y < surface->h)
		*((Uint32*)(surface->pixels) + x + y * surface->w) = col;
}

int		win_to_map(int x)
{
	return ((int)((double)x / (double)SCALE - 1.0));
}

int		map_to_win(int x)
{
	return (x * SCALE + SCALE);
}

t_point	point_to_map(t_point p)
{
	return (ft_pointdef(win_to_map(p.x), win_to_map(p.y)));
}

t_point	point_to_win(t_point p)
{
	return (ft_pointdef(map_to_win(p.x), map_to_win(p.y)));
}
