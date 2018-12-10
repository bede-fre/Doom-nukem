/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:17:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 11:40:08 by lguiller         ###   ########.fr       */
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
	return (wall == WOOD || wall == METAL || wall == STONE || wall == ICE
		|| wall == DOOR_C || wall == DOOR_I || wall == DOOR_R
		|| wall == BARREL || wall == ENNEMY || wall == GIRL);
}

int		is_displayable(char c)
{
	return (c == WOOD || c == METAL || c == STONE || c == ICE || c == WOOD_S
		|| c == METAL_S || c == STONE_S || c == ICE_S || c == DOOR_C
		|| c == TP_S);
}

int		is_door(char map[MAPY][MAPX], t_ray *ray)
{
	double t;

	t = (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x), map));
	return (map[to_map(ray->y - t)][to_map(ray->x - t)] != DOOR_I
		&& map[to_map(ray->y + t)][to_map(ray->x + t)] != DOOR_I
		&& map[to_map(ray->y - t)][to_map(ray->x - t)] != DOOR_R
		&& map[to_map(ray->y + t)][to_map(ray->x + t)] != DOOR_R);
}
