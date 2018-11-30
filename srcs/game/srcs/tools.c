/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:17:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/30 10:02:55 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		to_win(int x)
{
	return ((int)((double)x * BLOCK_SIZE));
}

int		to_map(double x)
{
	return ((int)(x / BLOCK_SIZE));
}

int		is_wall(char wall)
{
	return (wall == T_A || wall == T_B || wall == T_C || wall == T_D
		|| wall == T_DOOR_C || wall == T_DOOR_I || wall == T_DOOR_R);
}

int		is_displayable(char c)
{
	return (c != T_A && c != T_B && c != T_C && c != T_D && c != T_AS
		&& c != T_BS && c != T_CS && c != T_DS && c != T_DOOR_C
		&& c != TP_S);
}

int		is_door(char map[MAPY][MAPX], t_ray *ray)
{
	double t;

	t = (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x), map));
	return (map[to_map(ray->y - t)][to_map(ray->x - t)] != T_DOOR_I
		&& map[to_map(ray->y + t)][to_map(ray->x + t)] != T_DOOR_I
		&& map[to_map(ray->y - t)][to_map(ray->x - t)] != T_DOOR_R
		&& map[to_map(ray->y + t)][to_map(ray->x + t)] != T_DOOR_R);
}
