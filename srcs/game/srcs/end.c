/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:08:36 by cmace             #+#    #+#             */
/*   Updated: 2018/11/27 14:23:47 by cmace            ###   ########.fr       */
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
		if (soundend == 1)
		{
			Mix_PlayMusic(all->musics.win, 1);
			soundend = 0;
		}
	}
}
