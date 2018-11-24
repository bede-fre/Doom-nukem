/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:17:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/22 10:04:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		to_win(int x)
{
	return (x * BLOCK_SIZE / ZOOM);
}

int		to_map(double x)
{
	return ((int)(x / BLOCK_SIZE));
}

int		is_wall(char wall)
{
	return (wall == T_A || wall == T_B || wall == T_C || wall == T_D
		|| wall == T_DOOR_C || wall == T_DOOR_M);
}

int		is_displayable(char c)
{
	return (c != T_A && c != T_B && c != T_C && c != T_D && c != T_A_S
		&& c != T_B_S && c != T_C_S && c != T_D_S && c != T_DOOR_C);
}

int		is_door(char map[MAPY][MAPX], t_ray *ray)
{
	return (map[to_map(ray->y - (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))]
			[to_map(ray->x - (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))] != T_DOOR_M
		&& map[to_map(ray->y + (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))]
			[to_map(ray->x + (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))] != T_DOOR_M);
}