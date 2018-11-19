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

int	to_map(double x)
{
	return ((int)(x / BLOCK_SIZE));
}

int	is_wall(char wall)
{
	return (wall == T_A || wall == T_B || wall == T_C || wall == T_D
						|| wall == T_DOOR_C || wall == T_DOOR_M);
}

float	timer(float add)
{
	static float timer = 0.0;

	if (timer == 1.0)
	{
		return (timer);
	}
	timer += add;
	return (timer);
}