/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 11:55:11 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/19 10:40:03 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_clear_minimap(t_img *ptr)
{
	int x;
	int y;

	y = -1;
	while (++y < INFOY)
	{
		x = -1;
		while (++x < INFOX)
			ft_fill_pixel(ptr, x, y, 0xFF000000);
	}
}

static void	ft_rect(t_img *ptr, int x, int y, int c)
{
	t_coord	p1;
	t_coord	p2;

	p1.y = (y *= (BLOCK_SIZE / ZOOM));
	p2.x = (x *= (BLOCK_SIZE / ZOOM)) + (BLOCK_SIZE / ZOOM);
	p2.y = y + (BLOCK_SIZE / ZOOM);
	while (++p1.y + 1 < p2.y)
	{
		p1.x = x;
		while (++p1.x + 1 < p2.x)
			ft_fill_pixel(ptr, p1.x, p1.y, c);
	}
}

void		ft_perso(t_img *ptr, double x, double y)
{
	t_fcoord	p1;
	t_fcoord	p2;

	p1.y = -P_SIZE;
	p2.x = P_SIZE;
	p2.y = P_SIZE;
	while (++p1.y <= p2.y)
	{
		p1.x = -P_SIZE;
		while (++p1.x <= p2.x)
			ft_fill_pixel(ptr, x / ZOOM + p1.x, y / ZOOM + p1.y, RED);
	}
}

void		ft_print_map(t_img *ptr, char map[MAPY][MAPX])
{
	int		x;
	int		y;

	ft_clear_minimap(ptr);
	y = -1;
	while (++y < BUFF_SIZE)
	{
		x = -1;
		while (++x < BUFF_SIZE)
		{
			if (map[y][x] == T_A || map[y][x] == T_B || map[y][x] == T_C
				|| map[y][x] == T_D)
				ft_rect(ptr, x, y, WHITE);
			else if (map[y][x] == T_A_S || map[y][x] == T_B_S
				|| map[y][x] == T_C_S || map[y][x] == T_D_S)
				ft_rect(ptr, x, y, GREY);
			else if (map[y][x] == TP_S)
				ft_rect(ptr, x, y, LIGHT_GREEN);
			else if (map[y][x] == TP_E)
				ft_rect(ptr, x, y, GREEN);
		}
	}
}
