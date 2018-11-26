/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:37:05 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/26 10:11:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	jump_and_crouch(t_all *all)
{
	static int jump = FALSE;

	if (all->keys_tab[KEY_CTRL] && all->wall_gap >= 0.0 && all->wall_gap < 1.0)
		all->wall_gap += JUMP_SPEED;
	else if (!all->keys_tab[KEY_CTRL] && all->wall_gap > 0.0)
	{
		all->wall_gap -= JUMP_SPEED;
		all->wall_gap = (all->wall_gap <= 0.0) ? 0.0 : all->wall_gap;
	}
	else if (jump && (all->s_jump = 1))
	{
		all->jump = 0;
		all->wall_gap -= JUMP_SPEED;
		jump = (all->wall_gap <= -1.0) ? FALSE : TRUE;
	}
	else if (all->keys_tab[KEY_SPACEBAR] && all->wall_gap == 0.0
		&& all->stamina >= JUMP_STA && (all->jump = 1))
		jump = TRUE;
	else if (all->wall_gap < 0.0)
	{
		all->wall_gap += JUMP_SPEED;
		if (all->wall_gap >= 0.0 && (all->s_jump = 0))
			all->wall_gap = 0.0;
	}
}
