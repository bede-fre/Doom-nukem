/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:04:13 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/22 10:44:11 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

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

int		ft_wall_height_on_screen(double dist)
{
	return ((int)((((double)WINX / 2.0) / tan(ft_rad(FOV / 2.0))
		* (CAM_HEIGHT) / dist) * 2.0));
}

void	display_map(char map[MAPY][MAPX])
{
	int i;
	int j;

	i = 0;
	while (i < MAPY)
	{
		j = 0;
		while (j < MAPX)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	display_float_map(float map[MAPY][MAPX])
{
	int i;
	int j;

	i = 0;
	while (i < MAPY)
	{
		j = 0;
		while (j < MAPX)
		{
			printf("%f", map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}