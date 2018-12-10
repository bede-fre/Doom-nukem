/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:22:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 12:17:04 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		ft_print_sprite(t_all *all, int x, int i, double h)
{
	t_mat3	sprite;
	t_mat3	player;
	double	angle;
	double	cpt;
	double	col;

	angle = 0.0;
	if (all->rc.map[to_map(all->var.tp.y)][to_map(all->var.tp.x)] == GIRL)
	{
		sprite = ft_vecdef(all->var.tp.x, all->var.tp.y, 0.0);
		player = ft_vecdef(all->p.x, all->p.y, 0.0);
		angle = ft_vecangle(ft_vecsub(player, sprite), all->girl_vec)
			* ft_signe(ft_cross_product(ft_vecsub(player, sprite),
			all->girl_vec).z);
	}
	col = (BLOCK_SIZE / 2.0) + (ft_signe(ft_cross_product(all->var.v_sprite,
		all->var.v_inter).z) * (tan(ft_rad(ft_vecangle(all->var.v_sprite,
		all->var.v_inter))) * ft_vecnorm(all->var.v_sprite)));
	cpt = ((double)i - (all->start_wall - ((h / 4.0) * (2.0 + all->wall_gap))))
		* (BLOCK_SIZE / h) - (BLOCK_SIZE / 2.0);
	if (ft_find_color3(all, cpt, col, angle) !=
		(int)ALPHA && col >= 0.0 && col < 64.0)
		ft_fill_pixel(&all->fp, x, i, ft_find_color3(all, cpt, col, angle));
}

static void		print_col(t_all *all, int x)
{
	int		i;
	double	h;
	int		gap;

	h = ft_wall_height_on_screen(ft_vecnorm(all->var.v_sprite));
	gap = all->start_wall - ((h / 4.0) * (2.0 + all->wall_gap));
	i = -1;
	while (++i < h)
		ft_print_sprite(all, x, i + gap, h);
}

void			print_sprites(t_all *all, int x)
{
	const t_mat3	inter = ft_vecdef(all->rc.ray.x, all->rc.ray.y, 0.0);
	const t_mat3	player = ft_vecdef(all->p.x, all->p.y, 0.0);
	const t_mat3	vect = ft_vecnormalize(ft_vecsub(player, inter));
	const float		dist = (float)ft_vecnorm(ft_vecsub(player, inter));

	all->var.save = ft_pointdef(to_map(player.x), to_map(player.y));
	all->var.i = 0.0f;
	while ((all->var.i += 1.0f) < dist)
	{
		all->var.tp = ft_vecadd(ft_vecscale(vect, all->var.i), inter);
		all->var.p = ft_pointdef(to_map(all->var.tp.x), to_map(all->var.tp.y));
		if (is_sprite(all->rc.map[to_map(all->var.tp.y)][to_map(all->var.tp.x)])
		&& (all->var.p.x != all->var.save.x || all->var.p.y != all->var.save.y)
		&& (to_map(player.x) != all->var.p.x
		|| to_map(player.y) != all->var.p.y))
		{
			all->var.save = ft_pointdef(to_map(all->var.tp.x),
				to_map(all->var.tp.y));
			all->var.tp.x = to_win(to_map(all->var.tp.x)) + BLOCK_SIZE / 2.0;
			all->var.tp.y = to_win(to_map(all->var.tp.y)) + BLOCK_SIZE / 2.0;
			all->var.v_inter = ft_vecsub(inter, player);
			all->var.v_sprite = ft_vecsub(all->var.tp, player);
			print_col(all, x);
		}
	}
}
