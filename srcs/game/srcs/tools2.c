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

int		is_door(char map[MAPY][MAPX], t_ray *ray)
{
	return (map[to_map(ray->y - (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))]
			[to_map(ray->x - (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))] != T_DOOR_M
		&& map[to_map(ray->y + (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))]
			[to_map(ray->x + (64 * door_timer(0.0, to_map(ray->y), to_map(ray->x),
			map[to_map(ray->y)][to_map(ray->x)])))] != T_DOOR_M);
}

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
