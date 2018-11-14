/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:07:26 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/12 16:24:54 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	fill_rect(SDL_Surface *surface, t_point coord, Uint32 col)
{
	const t_point	dim = {SCALE, SCALE};
	t_point			i;

	i.y = 0;
	while (++i.y < dim.y)
	{
		i.x = 0;
		while (++i.x < dim.x)
			fill_px(surface, coord.x + i.x, coord.y + i.y, col);
	}
}

void	fill_border(SDL_Surface *surface, t_point pos, int l, Uint32 col)
{
	const int		border = 2;
	t_point			i;

	i.y = -1;
	while (++i.y <= l)
	{
		i.x = -1;
		while (++i.x <= l)
			if (i.x < border || i.x > l - border ||
				i.y < border || i.y > l - border)
				fill_px(surface, pos.x + i.x, pos.y + i.y, col);
	}
}

void	fill_cross(SDL_Surface *surface, t_point coord, Uint32 col)
{
	const t_point	dim = {SCALE, SCALE};
	int				i;

	i = 0;
	while (++i < dim.y)
	{
		fill_px(surface, coord.x + i, coord.y + i, col);
		fill_px(surface, coord.x + i, coord.y - i + dim.y, col);
	}
}
