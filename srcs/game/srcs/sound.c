/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:38:49 by cmace             #+#    #+#             */
/*   Updated: 2018/11/26 20:09:34 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		mute_sound(t_all *all)
{	
	if (!all->keys_tab[KEY_M])
	{
		Mix_VolumeMusic(MIX_MAX_VOLUME);
		Mix_Volume(-1, MIX_MAX_VOLUME);
	}
	else
	{
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win,
			all->hud.s_mute.ptr, 400, WINY - 85);
		Mix_VolumeMusic(0);
		Mix_Volume(-1, 0);
	}
}
