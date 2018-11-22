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
		&& c != T_B_S && c != T_C_S && c != T_D_S && c != T_DOOR_M
		&& c != T_DOOR_C);
}

float	timer(float add, int x, int y, char c)
{
	static float timer[32][32];

	if (c == T_DOOR_C || c == T_DOOR_O)
	{
		if (c == T_DOOR_C)
			timer[y][x] = 0.0f;
		else if (c == T_DOOR_O)
			if (timer[y][x] == 1.0f)
				return (timer[y][x]);
		if (timer[y][x] >= 0.66)
			timer[y][x] += add * 1.25;
		else if (timer[y][x] >= 0.90)
			timer[y][x] = 1.0;
		timer[y][x] += add;
		return (timer[y][x]);
	}
	return (0.0f);
}
