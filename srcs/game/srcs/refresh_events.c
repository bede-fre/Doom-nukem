/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:45:34 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/23 17:58:35 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	refresh_events(t_all *all)
{
	if (all->keys_tab[KEY_CTRL])
		all->speed = CROUCH_SPEED;
	else if (all->keys_tab[KEY_SHIFT] && all->keys_tab[KEY_W]
		&& all->stamina > 0)
		all->speed = RUN_SPEED;
	else if (all->keys_tab[KEY_W] || all->keys_tab[KEY_A] ||
		all->keys_tab[KEY_S] || all->keys_tab[KEY_D])
		all->speed = MOVE_SPEED;
	else
		all->speed = 0;
	if (all->keys_tab[KEY_L])
		system("leaks doom-nukem | grep 'leaked bytes'");
	(all->keys_tab[KEY_A]) ? ft_strafing(all, 1.0) : 0;
	(all->keys_tab[KEY_D]) ? ft_strafing(all, -1.0) : 0;
	(all->keys_tab[KEY_W]) ? ft_moving(all, 1.0) : 0;
	(all->keys_tab[KEY_S]) ? ft_moving(all, -1.0) : 0;
	(all->keys_tab[KEY_Q]) ? all->p.a += ft_rad(ROT_SPEED) : 0;
	(all->keys_tab[KEY_E]) ? all->p.a -= ft_rad(ROT_SPEED) : 0;
	(all->keys_tab[KEY_F]) ? open_door(all) : 0;
	all->s_idle = (is_movement(all->keys_tab) ? 0 : 1);
	all->skip = (all->keys_tab[KEY_ENTER]) ? 1 : 0;
}
