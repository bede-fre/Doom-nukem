/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:11:18 by toliver           #+#    #+#             */
/*   Updated: 2018/10/16 13:51:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	mapdraw(t_zone *zone, t_img *map)
{
	int		i;
	t_zone	*tmp_z;
	t_wall	*tmp_w;

	tmp_z = zone;
	while (tmp_z)
	{
		i = -1;
		tmp_w = tmp_z->wall;
		while (tmp_w->num != tmp_z->wall->num || !(++i))
		{
			ft_putline(ft_vecscale(tmp_w->origin, 10.0),
					ft_vecscale(tmp_w->next->origin, 10.0), map, 0xcccccc);
			tmp_w = tmp_w->next;
		}
		tmp_z = tmp_z->next;
	}
}

void		mapimgalloc(t_zone *zone, t_img *map, t_doom *env)
{
	int		i;
	t_vec	max;
	t_zone	*tmp_z;
	t_wall	*tmp_w;

	max.x = 0.0;
	max.y = 0.0;
	tmp_z = zone;
	while (tmp_z)
	{
		i = -1;
		tmp_w = tmp_z->wall;
		while (tmp_w->num != tmp_z->wall->num || !(++i))
		{
			if (tmp_w->origin.x > max.x)
				max.x = tmp_w->origin.x;
			if (tmp_w->origin.y > max.y)
				max.y = tmp_w->origin.y;
			tmp_w = tmp_w->next;
		}
		tmp_z = tmp_z->next;
	}
	img_get(map, (int)(max.x * 10.0 + 1.0), (int)(max.y * 10.0 + 1.0), env);
	mapdraw(zone, map);
}
