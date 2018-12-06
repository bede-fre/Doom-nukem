/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:50:45 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/06 12:46:22 by lguiller         ###   ########.fr       */
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
	if (c == S_BARREL || c == S_PILLAR)
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
	t_sprt	*current;

	current = NULL;
	if (p.ray_infos)
	{
		if (!ray->list)
		{
			ray->list = (t_sprt*)ft_memalloc(sizeof(t_list));
			ray->list->center = ft_vecdef(to_win(to_map(ray->x)) +
			(BLOCK_SIZE / 2.0), to_win(to_map(ray->y)) + (BLOCK_SIZE / 2.0), 0.0);
			ray->list->inter = ft_vecdef(ray->x, ray->y, 0.0);
			ray->list->dist = ft_vecnorm(ft_vecsub(ray->sprite,
				ft_vecdef(p.x, p.y, 0.0)));
			ray->list->next = NULL;
			ray->list->prev = NULL;
		}
		else
		{
			current = ray->list;
			while (current->next)
				current = current->next;
			current->next = (t_sprt*)ft_memalloc(sizeof(t_sprt));
			current->next->prev = current;
			current->next->center = ft_vecdef(to_win(to_map(ray->x)) +
			(BLOCK_SIZE / 2.0), to_win(to_map(ray->y)) + (BLOCK_SIZE / 2.0), 0.0);
			current->next->inter = ft_vecdef(ray->x, ray->y, 0.0);
			current->next->dist = ft_vecnorm(ft_vecsub(ray->sprite,
				ft_vecdef(p.x, p.y, 0.0)));
			current->next->next = NULL;
		}
	}

	ray->sprite = ft_vecdef(to_win(to_map(ray->x)) + (BLOCK_SIZE / 2.0),
		to_win(to_map(ray->y)) + (BLOCK_SIZE / 2.0), 0.0);
	ray->inter = ft_vecdef(ray->x, ray->y, 0.0);
	ray->sprite_dist = ft_vecnorm(ft_vecsub(ray->sprite,
		ft_vecdef(p.x, p.y, 0.0)));
}

void	free_lst(t_sprt **list)
{
	t_sprt *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if (*list)
			free((void*)*list);
		*list = NULL;
		*list = tmp;
	}
}
