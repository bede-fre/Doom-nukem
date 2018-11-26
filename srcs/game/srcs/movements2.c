/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:37:05 by lguiller          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/26 19:54:50 by cmace            ###   ########.fr       */
=======
/*   Updated: 2018/11/26 15:56:44 by lguiller         ###   ########.fr       */
>>>>>>> 02e0bd10fbc28a324c866191600162bfabc0b010
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	jump(t_all *all)
{
	static int jump;

	if (jump && (all->s_jump = 1))
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

static void	fly(t_all *all)
{
	if (all->keys_tab[KEY_SPACEBAR] && (all->s_jump = 1))
		all->wall_gap -= (all->wall_gap > -1) ? JUMP_SPEED : 0.0;
	else if (all->keys_tab[KEY_CTRL])
	{
		all->wall_gap += (all->wall_gap < 0) ? JUMP_SPEED : 0.0;
		if (all->wall_gap >= 0)
			all->s_jump = 0;
	}
}

void		jump_and_crouch(t_all *all)
{
	if (all->keys_tab[KEY_CTRL] && all->wall_gap >= 0.0 && all->wall_gap < 1.0)
		all->wall_gap += JUMP_SPEED;
	else if (!all->keys_tab[KEY_CTRL] && all->wall_gap > 0.0)
	{
		all->wall_gap -= JUMP_SPEED;
		all->wall_gap = (all->wall_gap <= 0.0) ? 0.0 : all->wall_gap;
	}
	if (all->keys_tab[KEY_X])
		fly(all);
	else
		jump(all);
}
