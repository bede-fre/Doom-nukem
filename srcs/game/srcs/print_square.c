/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:04:01 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/07 12:06:39 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	print_square(t_all *all)
{
	const t_point	dim = {48, 48};
	const t_point	pos = {WINX / 2 + 128, WINY - dim.y};
	const int		border = 1;
	t_point			p;

	p.y = -1;
	while (++p.y < dim.y)
	{
		p.x = -1;
		while (++p.x < dim.x)
		{
			if (p.x < border || p.x >= dim.x - border
			|| p.y < border || p.y >= dim.y - border)
				ft_fill_pixel(&all->fp, p.x - (dim.x / 2)
				+ pos.x, p.y - (dim.y / 2) + pos.y, WHITE);
		}
	}
}
