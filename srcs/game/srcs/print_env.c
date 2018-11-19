/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/13 15:43:48 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		ft_wall_height_on_screen(double dist)
{
	return ((int)((((double)WINX / 2.0) / tan(ft_rad(FOV / 2.0))
		* (CAM_HEIGHT) / dist) * 2.0));
}

static int		ft_color_textures(t_img *ptr, double cpt, int col)
{
	if (col < 0)
		return (ft_rgba(0,0,0,255));
	return (ft_rgba(
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 2],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 1],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl)],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 3]));
}

static int		ft_find_color(t_all *all, double cpt, int col)
{
	char	hit_wall;

	hit_wall = all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)];
	if (hit_wall == 'A' || hit_wall == 'a')
		return (ft_color_textures(&all->textures.img_n, cpt, col));
	else if (hit_wall == 'B' || hit_wall == 'b')
		return (ft_color_textures(&all->textures.img_e, cpt, col));
	else if (hit_wall == 'C' || hit_wall == 'c')
		return (ft_color_textures(&all->textures.img_s, cpt, col));
	else if (hit_wall == 'D' || hit_wall == 'd')
		return (ft_color_textures(&all->textures.img_w, cpt, col));
	else if (hit_wall == '-' || hit_wall == '~')
		return (ft_color_textures(&all->textures.img_d, cpt, col));
	else if (hit_wall == '|')
		return (ft_color_textures(&all->textures.img_d, cpt, col - 32));
	else
		return (ft_color_textures(&all->textures.img_f, cpt, col));
}

static void		ft_print_textures(t_all *all, int x, int i, double h)
{
	int		col;
	double	cpt;

	cpt = ((double)i - all->start_wall) * (BLOCK_SIZE / (float)h);
	if (all->keys_tab[KEY_SPACEBAR] && !all->keys_tab[KEY_CTRL])
		cpt -= (BLOCK_SIZE / 4) * ((all->wall_gap1 - 2.0f) / 2.0f);
	else if (all->wall_gap1 > 2.0f)
		cpt -= (BLOCK_SIZE / 4) * ((all->wall_gap1 - 2.0f) / 2.0f);
	else
		cpt += (BLOCK_SIZE / 4) * ((all->wall_gap2 - 2.0f) / 2.0f);
	if (all->rc.ray.hit == N_W || all->rc.ray.hit == S_W)
		col = (int)(all->rc.ray.x - ft_roundminf(all->rc.ray.x, BLOCK_SIZE));
	else
		col = (int)(all->rc.ray.y - ft_roundminf(all->rc.ray.y, BLOCK_SIZE));
	ft_fill_pixel(&all->fp, x, i, ft_find_color(all, cpt, col));
}

void			ft_print_on_screen(t_all *all, int x, double lens)
{
	int		i;
	double	h;

	i = -1;
	h = ft_wall_height_on_screen(all->rc.ray.dist * cos(lens));
	if (all->rc.ray.x < 0.0 || all->rc.ray.x >= (MAPX * BLOCK_SIZE)
		|| all->rc.ray.y < 0.0 || all->rc.ray.y >= (MAPY * BLOCK_SIZE))
		h = 0.0;
	while (++i < WINY)
	{
		if ((float)i <= (all->start_wall - ((float)h / all->wall_gap1)))
			ft_fill_pixel(&all->fp, x, i, TOP);
		else if ((float)i >= (all->start_wall + ((float)h / all->wall_gap2)))
			ft_fill_pixel(&all->fp, x, i, BOTTOM);
		else
		{
			if (all->keys_tab[KEY_T] == TRUE)
				ft_print_textures(all, x, i, h);
			else if (all->keys_tab[KEY_T] == FALSE)
				ft_fill_pixel(&all->fp, x, i, all->rc.ray.hit);
		}
	}
}
