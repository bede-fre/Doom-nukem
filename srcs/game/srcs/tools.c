/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:17:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/12 14:54:16 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		to_map(double x)
{
	return ((int)(x / BLOCK_SIZE));
}

int		is_wall(char wall)
{
	return (wall == T_A || wall == T_B || wall == T_C || wall == T_D
						|| wall == T_DOOR_C || wall == T_DOOR_M);
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