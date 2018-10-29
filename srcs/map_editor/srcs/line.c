/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:45:12 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 13:56:15 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

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
