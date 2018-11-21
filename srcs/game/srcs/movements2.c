/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:37:05 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/21 11:49:14 by lguiller         ###   ########.fr       */
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
		if (all->wall_gap <= 0.0)
			all->wall_gap = 0.0;
	}
	else if (jump)
	{
		all->wall_gap -= JUMP_SPEED;
		jump = (all->wall_gap <= -1.0) ? FALSE : TRUE;
	}
	else if (all->keys_tab[KEY_SPACEBAR] && all->wall_gap == 0.0)
		jump = TRUE;
	else if (all->wall_gap < 0.0)
	{
		all->wall_gap += JUMP_SPEED;
		if (all->wall_gap >= 0.0)
			all->wall_gap = 0.0;
	}
}

void	open_door(t_all *all)
{
	all->a = all->p.a - ft_rad(((WINY) - (WINX / 2) - 1) * RAY_ANGLE);
	ft_fp_hori(&all->rc.ray_h, &all->p, all->rc.map, all->a);
	ft_fp_vert(&all->rc.ray_v, &all->p, all->rc.map, all->a);
	if (all->rc.ray_h.dist != all->rc.ray_h.dist ||
		all->rc.ray_v.dist != all->rc.ray_v.dist)
		all->rc.ray = (all->rc.ray_h.dist != all->rc.ray_h.dist) ?
		all->rc.ray_v : all->rc.ray_h;
	else
		all->rc.ray = (all->rc.ray_h.dist <= all->rc.ray_v.dist) ?
		all->rc.ray_h : all->rc.ray_v;
	printf("all->rc.ray.x: %f\n", all->rc.ray.x);
	printf("all->rc.ray.y: %f\n", all->rc.ray.y);

	printf("Lettre: %c\n", all->rc.map[to_map(all->rc.ray_v.y)][to_map(all->rc.ray_v.x)]);
	printf("Y: %d  X: %d\n", to_map(all->rc.ray_v.y), to_map(all->rc.ray_v.x));

	printf("all->a: %f\n", all->a);

	// printf("all->rc.ray.dx: %f\n", all->rc.ray.dx);
	// printf("all->rc.ray.fx: %f\n", all->rc.ray.fx);
	// printf("all->rc.ray.xa: %f\n", all->rc.ray.xa);
	
	// printf("all->rc.ray_h.x: %f\n", all->rc.ray_h.x);
	// printf("all->rc.ray_h.dx: %f\n", all->rc.ray_h.dx);
	// printf("all->rc.ray_h.fx: %f\n", all->rc.ray_h.fx);
	// printf("all->rc.ray_h.xa: %f\n", all->rc.ray_h.xa);

	// printf("all->rc.ray_v.x: %f\n", all->rc.ray_v.x);
	// printf("all->rc.ray_v.dx: %f\n", all->rc.ray_v.dx);
	// printf("all->rc.ray_v.fx: %f\n", all->rc.ray_v.fx);
	// printf("all->rc.ray_v.xa: %f\n", all->rc.ray_v.xa);

	// printf("all->prevx: %f\n", all->x);

	// if (all->rc.map[to_map(all->rc.ray_v.y)][to_map(all->rc.ray_v.x)] == T_DOOR_C && all->rc.ray.dist <= 100) {
	// 		all->rc.map[to_map(all->rc.ray_v.y)][to_map(all->rc.ray_v.x)] = T_DOOR_O;
	// 		ft_putstr("door open\n");
	// } else if (all->rc.map[to_map(all->rc.ray_v.y)][to_map(all->rc.ray_v.x)] == T_DOOR_O && all->rc.ray.dist <= 100) {
	// 		all->rc.map[to_map(all->rc.ray_v.y)][to_map(all->rc.ray_v.x)] = T_DOOR_C;
	// 		ft_putstr("door close\n");
	// }
	all->rc.map[27][27] = T_DOOR_O;
}
