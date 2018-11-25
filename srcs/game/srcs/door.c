/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruellou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:11:47 by aruellou          #+#    #+#             */
/*   Updated: 2018/11/23 19:11:49 by aruellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	door_auto(char map[MAPY][MAPX], t_player p, t_point	i)
{
	if (door_timer(0.0, i.y, i.x, map[i.y][i.x]) == 1.0)
		map[i.y][i.x] = T_DOOR_O;
	if (map[i.y][i.x] == T_DOOR_O && sqrt(pow(((p.x / 64) - i.x), 2)
			+ pow(((p.y / 64) - i.y), 2)) >= 5)
		map[i.y][i.x] = T_DOOR_C;
}

void	door_update(float timer[MAPY][MAPX], char c)
{
	int i;
	int j;

	c = ' ';
	i = 0;
	while (i < MAPY)
	{
		j = 0;
		while (j < MAPX)
		{
			if (timer[i][j] >= 0.99)
				timer[i][j] = 1.0;
			else if (timer[i][j] != 0.0 && timer[i][j] != 1.0)
				timer[i][j] += DOOR_SPEED;
			j++;
		}
		i++;
	}
}

float	door_timer(float add, int x, int y, char c)
{
	static float timer[MAPY][MAPX];
	static int	 i = 0;

	if (i % 50000 == 0) {
		door_update(timer, c);
	}
	i++;
	if (c == T_DOOR_C || c == T_DOOR_I || c == T_DOOR_R || c == T_DOOR_O)
	{
		if (c == T_DOOR_C)
			timer[y][x] = 0.0;
		else if (c == T_DOOR_O)
			timer[y][x] = 1.0;
		else if (add)
			timer[y][x] += add;
		return (timer[y][x]);
	}
	return (0.0);
}

void	door_open(t_all *all)
{
	all->a = all->p.a - ft_rad((((WINX / 2) - 1) - (WINX / 2) - 1) * RAY_ANGLE);
	ft_fp_hori(&all->rc.ray_h, &all->p, all->rc.map, all->a);
	ft_fp_vert(&all->rc.ray_v, &all->p, all->rc.map, all->a);
	if (all->rc.ray_h.dist != all->rc.ray_h.dist ||
		all->rc.ray_v.dist != all->rc.ray_v.dist)
		all->rc.ray = (all->rc.ray_h.dist != all->rc.ray_h.dist) ?
		all->rc.ray_v : all->rc.ray_h;
	else
		all->rc.ray = (all->rc.ray_h.dist <= all->rc.ray_v.dist) ?
		all->rc.ray_h : all->rc.ray_v;
	if (all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)] == T_DOOR_C
	&& all->rc.ray.dist <= 100)
	{
		Mix_PlayChannel(-1, all->sounds.opendoor, 0);
		all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)] = T_DOOR_I;
		door_timer(DOOR_SPEED, to_map(all->rc.ray.y), to_map(all->rc.ray.x),
			all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)]);
	}
	all->lens -= ft_rad(RAY_ANGLE) * all->keys_tab[KEY_H];
	all->a -= ft_rad(RAY_ANGLE);
}
