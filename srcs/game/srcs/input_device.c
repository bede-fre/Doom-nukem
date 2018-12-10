/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_device.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/07 11:20:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		ft_key_press(int key, t_all *all)
{
	if (key == KEY_H || key == KEY_ENTER ||
		key == KEY_M)
		all->keys_tab[key] = (all->keys_tab[key] == FALSE) ? TRUE : FALSE;
	else if (key == KEY_X)
	{
		if (all->jetpack)
			all->keys_tab[key] = (all->keys_tab[key] == FALSE) ? TRUE : FALSE;
	}
	else
		all->keys_tab[key] = 1;
	if (key == ESC)
		ft_quit();
	return (1);
}

int		ft_key_release(int key, t_all *all)
{
	if (key != KEY_H && key != KEY_X && key != KEY_ENTER &&
		key != KEY_M)
		all->keys_tab[key] = 0;
	return (1);
}

int		ft_button_press(int key, int x, int y, t_all *all)
{
	double a;

	(void)y;
	a = all->p.a - ft_rad(((x - 1) - (WINX / 2) - 1) * RAY_ANGLE);
	if (key == 1)
	{
		all->p.ray_infos = 1;
		all->a = a;
		ft_print_ray_infos(all);
		all->p.ray_infos = 0;
	}
	return (0);
}

int		ft_mouse_motion(int x, int y, t_all *all)
{
	int diffx;
	int diffy;

	if (all->prevx == -8000 && all->prevy == -8000)
	{
		all->prevx = x;
		all->prevy = y;
	}
	else
	{
		diffx = all->prevx - x;
		diffy = all->prevy - y;
		if (!all->skip)
		{
			all->p.a += ((double)diffx / 100.0);
			all->start_wall += ((double)diffy * 4.0);
		}
		all->prevx = x;
		all->prevy = y;
	}
	return (0);
}
