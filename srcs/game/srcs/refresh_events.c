/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:45:34 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/23 10:55:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	refresh_events(t_all *all)
{
	if (all->keys_tab[KEY_CTRL] == TRUE)
		all->speed = CROUCH_SPEED;
	else if (all->keys_tab[KEY_SHIFT] == TRUE && all->keys_tab[KEY_W] == TRUE
		&& all->stamina > 0)
		all->speed = RUN_SPEED;
	else
		all->speed = MOVE_SPEED;
	if (all->keys_tab[KEY_L])
		system("leaks doom-nukem | grep 'leaked bytes'");
	(all->keys_tab[KEY_A] == TRUE) ? ft_strafing(all, 1.0) : 0;
	(all->keys_tab[KEY_D] == TRUE) ? ft_strafing(all, -1.0) : 0;
	(all->keys_tab[KEY_W] == TRUE) ? ft_moving(all, 1.0) : 0;
	(all->keys_tab[KEY_S] == TRUE) ? ft_moving(all, -1.0) : 0;
	(all->keys_tab[KEY_Q] == TRUE) ? all->p.a += ft_rad(ROT_SPEED) : 0;
	(all->keys_tab[KEY_E] == TRUE) ? all->p.a -= ft_rad(ROT_SPEED) : 0;
	(all->keys_tab[KEY_F] == TRUE) ? open_door(all) : 0;
	all->s_idle = (is_movement(all->keys_tab) ? 0 : 1);
	all->skip = (all->keys_tab[KEY_ENTER] == TRUE) ? 1 : 0;
}
