/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:48:29 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/30 13:55:36 by lguiller         ###   ########.fr       */
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

/*
** CREATION D'UN ROND DE COORDONNEES P, DE RAYON R ET DE COULEUR COL
** DANS UNE SURFACE
*/

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

static void	fill_line(SDL_Surface *surface, t_bres *algo, Uint32 col)
{
	algo->cumul = algo->da / 2;
	while (algo->i <= algo->da)
	{
		algo->a += algo->cpta;
		algo->cumul += algo->db;
		if (algo->cumul >= algo->da)
		{
			algo->cumul -= algo->da;
			algo->b += algo->cptb;
		}
		fill_px(surface, algo->a, algo->b, col);
		algo->i++;
	}
}

static void	fill_column(SDL_Surface *surface, t_bres *algo, Uint32 col)
{
	algo->cumul = algo->db / 2;
	while (algo->i <= algo->db)
	{
		algo->b += algo->cptb;
		algo->cumul += algo->da;
		if (algo->cumul >= algo->db)
		{
			algo->cumul -= algo->db;
			algo->a += algo->cpta;
		}
		fill_px(surface, algo->a, algo->b, col);
		algo->i++;
	}
}

/*
** CREATION D'UNE LIGNE RELIANT LE POINT P1 ET LE POINT P2 ET DE COULEUR COL
** DANS UNE SURFACE
*/

void		line(SDL_Surface *surface, t_point p1, t_point p2, Uint32 col)
{
	t_bres algo;

	algo.a = p1.x;
	algo.b = p1.y;
	algo.da = p2.x - algo.a;
	algo.db = p2.y - algo.b;
	algo.cpta = (algo.da > 0) ? 1 : -1;
	algo.cptb = (algo.db > 0) ? 1 : -1;
	algo.da = abs(algo.da);
	algo.db = abs(algo.db);
	algo.i = 1;
	fill_px(surface, algo.a, algo.b, col);
	if (algo.da > algo.db)
		fill_line(surface, &algo, col);
	else
		fill_column(surface, &algo, col);
}
