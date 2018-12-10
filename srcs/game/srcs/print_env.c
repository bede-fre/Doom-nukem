/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/06 16:38:09 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_print_textures(t_all *all, int x, int i, double h)
{
	int		col;
	double	cpt;

	cpt = ((double)i - (all->start_wall - ((h / 4.0) * (2.0 + all->wall_gap))))
		* (BLOCK_SIZE / h) - (BLOCK_SIZE / 2.0);
	col = ((all->rc.ray.hit == N_W || all->rc.ray.hit == S_W) ?
		(int)all->rc.ray.x : (int)all->rc.ray.y) % (int)BLOCK_SIZE;
	ft_fill_pixel(&all->fp, x, i, ft_find_color(all, cpt, col));
}

void			ft_print_on_screen(t_all *all, int x, double lens)
{
	int		i;
	double	h;

	i = -1;
	h = ft_wall_height_on_screen(all->rc.ray.dist * cos(lens)) / 4.0;
	if (all->rc.ray.x < 0.0 || all->rc.ray.x >= (MAPX * BLOCK_SIZE)
		|| all->rc.ray.y < 0.0 || all->rc.ray.y >= (MAPY * BLOCK_SIZE))
		h = 0.0;
	while (++i < WINY)
	{
		if ((double)i <= (all->start_wall - (h * (2.0 + all->wall_gap))))
			ft_fill_pixel(&all->fp, x, i, TOP);
		else if ((double)i >= (all->start_wall + (h * (2.0 - all->wall_gap))))
			ft_fill_pixel(&all->fp, x, i, BOTTOM);
		else
			ft_print_textures(all, x, i, h * 4.0);
	}
	print_sprites(all, x);
}
