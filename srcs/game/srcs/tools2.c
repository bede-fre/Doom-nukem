/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:04:13 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/22 15:38:51 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int		ft_wall_height_on_screen(double dist)
{
	return ((int)((((double)WINX / 2.0) / tan(ft_rad(FOV / 2.0))
		* (CAM_HEIGHT) / dist) * 2.0));
}

int		is_movement(int keys_tab[KEYS_TAB_SIZE])
{
	return (keys_tab[KEY_W] || keys_tab[KEY_A] || keys_tab[KEY_S] ||
		keys_tab[KEY_D] || keys_tab[KEY_CTRL] || keys_tab[KEY_SPACEBAR]);
}

void	init_image(t_mlx ptr, t_img *img, int x, int y)
{
	if (!(img->img = mlx_new_image(ptr.mlx, x, y)))
		ft_error("error", 14, perror);
	img->width = x;
	img->height = y;
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->endian);
}
