/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:47:46 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/22 12:10:48 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_stickman(t_all *all)
{
	all->hud.s_jump.ptr = mlx_xpm_file_to_image(all->ptr.mlx, SPR_JUMP,
		&all->hud.s_jump.width, &all->hud.s_jump.height);
	all->hud.s_run.ptr = mlx_xpm_file_to_image(all->ptr.mlx, SPR_RUN,
		&all->hud.s_run.width, &all->hud.s_run.height);
	all->hud.s_idle.ptr = mlx_xpm_file_to_image(all->ptr.mlx, SPR_IDLE,
		&all->hud.s_idle.width, &all->hud.s_idle.height);
	all->hud.s_walk.ptr = mlx_xpm_file_to_image(all->ptr.mlx, SPR_WALK,
		&all->hud.s_walk.width, &all->hud.s_walk.height);
	all->hud.s_crouch.ptr = mlx_xpm_file_to_image(all->ptr.mlx, SPR_CROUCH,
		&all->hud.s_crouch.width, &all->hud.s_crouch.height);
	if (!all->hud.s_jump.ptr || !all->hud.s_run.ptr || !all->hud.s_idle.ptr
		|| !all->hud.s_walk.ptr || !all->hud.s_crouch.ptr)
		ft_error("error", 20, perror);
}
