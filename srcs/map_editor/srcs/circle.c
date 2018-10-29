/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:23:37 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 15:17:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	fill_every_points(SDL_Surface *surface, t_point p1,
		t_point p2, Uint32 col)
{
	fill_px(surface, (p1.x + p2.x), (p1.y + p2.y), col);
	fill_px(surface, (p1.x + p2.y), (p1.y + p2.x), col);
	fill_px(surface, (p1.x - p2.x), (p1.y + p2.y), col);
	fill_px(surface, (p1.x - p2.y), (p1.y + p2.x), col);
	fill_px(surface, (p1.x + p2.x), (p1.y - p2.y), col);
	fill_px(surface, (p1.x + p2.y), (p1.y - p2.x), col);
	fill_px(surface, (p1.x - p2.x), (p1.y - p2.y), col);
	fill_px(surface, (p1.x - p2.y), (p1.y - p2.x), col);
}

void		circle(SDL_Surface *surface, t_point p, int r, Uint32 col)
{
	t_point	p2;
	int		h;
	int		k;

	h = r + 1;
	while (--h >= 0)
	{
		p2.x = 0;
		p2.y = h;
		k = p2.y - 1;
		while (p2.y >= p2.x)
		{
			fill_every_points(surface, p, p2, col);
			if (k >= 2 * p2.x)
				k = k - 2 * (p2.x++) - 1;
			else if (k < 2 * (h - p2.y))
				k = k + 2 * (p2.y--) - 1;
			else
			{
				k = k + 2 * (p2.y - p2.x - 1);
				--p2.y;
				++p2.x;
			}
		}
	}
}
