/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:37:05 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/19 14:23:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	jump_and_crouch(t_all *all)
{
	static int jump = FALSE;

	if (all->keys_tab[KEY_CTRL] && all->wall_gap >= 0.0 && all->wall_gap < 1.0)
		all->wall_gap += CROUCH_SPEED;
	else if (!all->keys_tab[KEY_CTRL] && all->wall_gap > 0.0)
	{
		all->wall_gap -= CROUCH_SPEED;
		if (all->wall_gap <= 0.0)
			all->wall_gap = 0.0;
	}
	else if (jump)
	{
		all->wall_gap -= JUMP_SPEED;
		jump = (all->wall_gap <= -1.0) ? FALSE : TRUE;
	}
	else if (all->keys_tab[KEY_SPACEBAR] && all->wall_gap == 0.0)
		jump = TRUE;
	else if (all->wall_gap < 0.0)
	{
		all->wall_gap += JUMP_SPEED;
		if (all->wall_gap >= 0.0)
			all->wall_gap = 0.0;
	}
}
