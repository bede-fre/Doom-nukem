/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:18 by toliver           #+#    #+#             */
/*   Updated: 2018/09/24 19:12:20 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void			mapdraw(t_zone **zones, t_img *map)
{
	int				i;
	int				ii;

	i = 0;
	while (zones[i])
	{	
		ii = 0;
		while (zones[i]->walls[ii])
		{
			if (zones[i]->walls[ii + 1])

				ft_putline(ft_vecscale(zones[i]->walls[ii]->origin, 10),
						ft_vecscale(zones[i]->walls[ii + 1]->origin, 10),
						map, 0xcccccc);
			else
				ft_putline(ft_vecscale(zones[i]->walls[ii]->origin, 10),
						ft_vecscale(zones[i]->walls[0]->origin, 10),
						map, 0xcccccc);
			ii++;
		}
		i++;
	}
}

void				mapimgalloc(t_zone **zones, t_img *map, t_doom *env)
{
	int				i;
	int				ii;
	float			maxx;
	float			maxy;
	
	i = 0;
	maxx = 0;
	maxy = 0;
	while (zones[i])
	{	
		ii = 0;
		while (zones[i]->walls[ii])
		{
			if (zones[i]->walls[ii]->origin.x > maxx)
				maxx = zones[i]->walls[ii]->origin.x;
			if (zones[i]->walls[ii]->origin.y > maxy)
				maxy = zones[i]->walls[ii]->origin.y; 
			ii++;
		}
		i++;
	}
	img_get(map, (int)(maxx * 10 + 1), (int)(maxy * 10 + 1), env);
	mapdraw(zones, map);
}
