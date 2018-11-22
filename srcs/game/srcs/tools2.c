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

void	update_door_status(t_all *all)
{
	if (timer(0.0, to_map(all->rc.ray.y), to_map(all->rc.ray.x),
			  all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)]) >= 0.9)
	{
		ft_putstr("ALL\n");
		all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)] = T_DOOR_O;
		display_map(all->rc.map);
	}
}

int		is_door(char map[MAPY][MAPX], t_ray *ray)
{
	return (map[to_map(ray->y - (64 * timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))]
			[to_map(ray->x - (64 * timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))] != T_DOOR_M
		&& map[to_map(ray->y + (64 * timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))]
			[to_map(ray->x + (64 * timer(0.0, to_map(ray->y), to_map(ray->x),
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