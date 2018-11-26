/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:08:36 by cmace             #+#    #+#             */
/*   Updated: 2018/11/26 16:16:01 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	it_is_the_end(t_all *all)
{
	static int soundend = 1;

	if (all->end)
	{
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win,
			all->end_img.img, 0, 0);
		Mix_VolumeMusic(10);
		if (soundend == 1)
		{
			Mix_PlayChannel(-1, all->sounds.win, 0);
			soundend = 0;
		}
	}
}
