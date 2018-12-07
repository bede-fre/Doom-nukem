/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stickman.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:22:54 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/07 11:24:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	print_stickman(t_all *all)
{
	if (all->s_jump)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->hud.s_jump.img,
		INFOX / 2, WINY - 85);
	else if (all->speed == RUN_SPEED)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->hud.s_run.img,
		INFOY / 2, WINY - 85);
	else if (all->speed == MOVE_SPEED)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->hud.s_walk.img,
		INFOX / 2, WINY - 85);
	else if (all->speed == CROUCH_SPEED)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win,
		all->hud.s_crouch.img, INFOX / 2, WINY - 85);
	else
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->hud.s_idle.img,
		INFOX / 2, WINY - 85);
}
