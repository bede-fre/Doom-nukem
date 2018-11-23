/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:37:05 by lguiller          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/22 19:01:26 by cmace            ###   ########.fr       */
=======
/*   Updated: 2018/11/23 10:40:26 by lguiller         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	jump_and_crouch(t_all *all)
{
	static int jump = FALSE;

	if (all->keys_tab[KEY_CTRL] && all->wall_gap >= 0.0 && all->wall_gap < 1.0)
		all->wall_gap += JUMP_SPEED;
	else if (!all->keys_tab[KEY_CTRL] && all->wall_gap > 0.0)
	{
		all->wall_gap -= JUMP_SPEED;
		all->wall_gap = (all->wall_gap <= 0.0) ? 0.0 : all->wall_gap;
	}
	else if (jump)
	{
		all->s_jump = 1;
		all->jump = 0;
		all->wall_gap -= JUMP_SPEED;
		jump = (all->wall_gap <= -1.0) ? FALSE : TRUE;
	}
	else if (all->keys_tab[KEY_SPACEBAR] && all->wall_gap == 0.0
		&& all->stamina > 0 && (all->jump = 1))
		jump = TRUE;
	else if (all->wall_gap < 0.0)
	{
		all->wall_gap += JUMP_SPEED;
		if (all->wall_gap >= 0.0 && (all->s_jump = 0))
			all->wall_gap = 0.0;
	}
}

void	open_door(t_all *all)
{
	all->a = all->p.a - ft_rad((((WINX / 2) - 1) - (WINX / 2) - 1) * RAY_ANGLE);
	ft_fp_hori(&all->rc.ray_h, &all->p, all->rc.map, all->a);
	ft_fp_vert(&all->rc.ray_v, &all->p, all->rc.map, all->a);
	if (all->rc.ray_h.dist != all->rc.ray_h.dist ||
		all->rc.ray_v.dist != all->rc.ray_v.dist)
		all->rc.ray = (all->rc.ray_h.dist != all->rc.ray_h.dist) ?
		all->rc.ray_v : all->rc.ray_h;
	else
		all->rc.ray = (all->rc.ray_h.dist <= all->rc.ray_v.dist) ?
		all->rc.ray_h : all->rc.ray_v;
	if (all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)] == T_DOOR_C
	&& all->rc.ray.dist <= 100)
	{
		all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)] = T_DOOR_O;
		Mix_PlayChannel(-1, all->sounds.opendoor, 0);
	}
	all->lens -= ft_rad(RAY_ANGLE) * all->keys_tab[KEY_H];
	all->a -= ft_rad(RAY_ANGLE);
}
