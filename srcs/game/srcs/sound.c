/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:38:49 by cmace             #+#    #+#             */
/*   Updated: 2018/11/27 10:51:38 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		mute_sound(t_all *all)
{
	const int	dim = (int)(BLOCK_SIZE / ZOOM) * 2;
	t_img		tmp;

	if (!all->keys_tab[KEY_M])
	{
		Mix_VolumeMusic(MIX_MAX_VOLUME);
		Mix_Volume(-1, MIX_MAX_VOLUME);
	}
	else
	{
		init_image(all->ptr, &tmp, dim, dim);
		scale_img(&tmp, &all->hud.mute);
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win,
			tmp.img, WINX - tmp.width - 10, 10);
		Mix_VolumeMusic(0);
		Mix_Volume(-1, 0);
	}
}
