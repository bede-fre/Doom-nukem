/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stamina_bar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:45:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/06 12:25:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		print_stamina_bar(t_img *img, int stamina, int col)
{
	const int	rate = (int)((double)BARW * ((double)stamina / STAMINA_MAX));
	const int	size = 2;
	t_point		p;

	p.y = -1;
	while (++p.y < BARH)
	{
		p.x = -1;
		while (++p.x < BARW)
		{
			if (p.x <= size || p.x >= BARW - size - 1 || p.y <= size
				|| p.y >= BARH - size - 1)
				ft_fill_pixel(img, p.x, p.y, BLACK);
			else if (p.x < rate)
				ft_fill_pixel(img, p.x, p.y, col);
			else
				ft_fill_pixel(img, p.x, p.y, ALPHA);
		}
	}
}

void		stamina_control(t_all *all)
{
	static int time;

	if (all->speed == RUN_SPEED || all->jump)
	{
		if (all->stamina > 0)
			all->stamina -= (all->jump) ? JUMP_STA : 2;
		time = 200;
	}
	else if ((time -= (time > 0) ? 1 : 0) == 0)
		all->stamina += (all->stamina < (int)STAMINA_MAX) ? 1 : 0;
}
