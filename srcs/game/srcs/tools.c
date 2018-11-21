/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:17:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/21 11:49:41 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	to_win(int x)
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

int		is_displayable(char map[MAPY][MAPX], t_ray *ray) {
	return (map[to_map(ray->y)][to_map(ray->x)] != T_A
		&& map[to_map(ray->y)][to_map(ray->x)] != T_B
		&& map[to_map(ray->y)][to_map(ray->x)] != T_C
		&& map[to_map(ray->y)][to_map(ray->x)] != T_D
		&& map[to_map(ray->y)][to_map(ray->x)] != T_A_S
		&& map[to_map(ray->y)][to_map(ray->x)] != T_B_S
		&& map[to_map(ray->y)][to_map(ray->x)] != T_C_S
		&& map[to_map(ray->y)][to_map(ray->x)] != T_D_S
		&& map[to_map(ray->y - (64 * timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))]
			[to_map(ray->x - (64 * timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))] != T_DOOR_O
		&& map[to_map(ray->y + (64 * timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))]
			[to_map(ray->x + (64 * timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))] != T_DOOR_O
		&& map[to_map(ray->y)][to_map(ray->x)] != T_DOOR_M
		&& map[to_map(ray->y)][to_map(ray->x)] != T_DOOR_C);
}

float	timer(float add, int x, int y, char c)
{
	static float timer[32][32];

	if (c == T_DOOR_C || c == T_DOOR_O)
	{
		if (c == T_DOOR_C)
			timer[y][x] = 0.0;
		else if (c == T_DOOR_O)
			if (timer[y][x] == 1.0)
				return (timer[y][x]);
		timer[y][x] += add;
		return (timer[y][x]);
	}
	return (0.0);
}