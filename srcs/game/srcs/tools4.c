/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:50:45 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 12:06:11 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_xpm(t_mlx ptr, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(ptr.mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_error("error", 11, perror);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->endian);
}

int		is_sprite(char c)
{
	if (c == BARREL || c == ENNEMY || c == LIGHTNING || c == JETPACK
		|| c == GIRL)
		return (1);
	return (0);
}

void	cpy_sprite_infos(t_raycast *rc)
{
	if (rc->ray_v.test)
	{
		rc->ray.sprite = rc->ray_v.sprite;
		rc->ray.inter = rc->ray_v.inter;
		if (rc->ray.dist > rc->ray_v.sprite_dist)
			rc->ray.test = 1;
	}
	else if (rc->ray_h.test)
	{
		rc->ray.sprite = rc->ray_h.sprite;
		rc->ray.inter = rc->ray_h.inter;
		if (rc->ray.dist > rc->ray_h.sprite_dist)
			rc->ray.test = 1;
	}
}

void	register_sprite(t_ray *ray, t_player p)
{
	ray->sprite = ft_vecdef(to_win(to_map(ray->x)) + (BLOCK_SIZE / 2.0),
		to_win(to_map(ray->y)) + (BLOCK_SIZE / 2.0), 0.0);
	ray->inter = ft_vecdef(ray->x, ray->y, 0.0);
	ray->sprite_dist = ft_vecnorm(ft_vecsub(ray->sprite,
		ft_vecdef(p.x, p.y, 0.0)));
}
