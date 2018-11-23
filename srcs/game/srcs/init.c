/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:22:58 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/23 10:44:09 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_init_player(char map[MAPY][MAPX], t_player *p)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MAPY)
	{
		x = -1;
		while (++x < MAPX)
		{
			if (map[y][x] == 's')
			{
				p->x = (double)x * BLOCK_SIZE + (BLOCK_SIZE / 2.0);
				p->y = (double)y * BLOCK_SIZE + (BLOCK_SIZE / 2.0);
				p->a = ft_rad(180.0);
				break ;
			}
		}
	}
}

void		ft_init_keys_tab(int (*keys_tab)[KEYS_TAB_SIZE])
{
	int i;

	i = -1;
	while (++i < KEYS_TAB_SIZE)
		keys_tab[0][i] = 0;
	keys_tab[0][KEY_H] = 1;
	keys_tab[0][KEY_T] = 1;
}

static void	init_textures(t_all *all, t_textures *textures)
{
	textures->img_n.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_NORTH, &textures->width, &textures->height);
	textures->img_s.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_SOUTH, &textures->width, &textures->height);
	textures->img_e.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_EAST, &textures->width, &textures->height);
	textures->img_w.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_WEST, &textures->width, &textures->height);
	textures->img_d.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_DOOR, &textures->width, &textures->height);
	textures->img_dr.img = mlx_xpm_file_to_image(all->ptr.mlx,
		TEXT_DOOR_R, &textures->width, &textures->height);
	if (!textures->img_n.img || !textures->img_s.img || !textures->img_e.img
	|| !textures->img_w.img || !textures->img_d.img || !textures->img_dr.img)
		ft_error("error", 11, perror);
}

static void	init_data_textures(t_textures *textures)
{
	textures->img_n.data = mlx_get_data_addr(textures->img_n.img,
		&textures->img_n.bpp, &textures->img_n.sl, &textures->img_n.endian);
	textures->img_s.data = mlx_get_data_addr(textures->img_s.img,
		&textures->img_s.bpp, &textures->img_s.sl, &textures->img_s.endian);
	textures->img_e.data = mlx_get_data_addr(textures->img_e.img,
		&textures->img_e.bpp, &textures->img_e.sl, &textures->img_e.endian);
	textures->img_w.data = mlx_get_data_addr(textures->img_w.img,
		&textures->img_w.bpp, &textures->img_w.sl, &textures->img_w.endian);
	textures->img_d.data = mlx_get_data_addr(textures->img_dr.img,
		&textures->img_dr.bpp, &textures->img_dr.sl, &textures->img_dr.endian);
	textures->img_dr.data = mlx_get_data_addr(textures->img_d.img,
		&textures->img_d.bpp, &textures->img_d.sl, &textures->img_d.endian);
}

void		ft_init_mlx(t_all *all, char *title)
{
	all->ptr.mlx = mlx_init();
	all->ptr.win = mlx_new_window(all->ptr.mlx, WINX, WINY, title);
	init_image(all->ptr, &all->info, INFOX, INFOY);
	init_image(all->ptr, &all->fp, WINX, WINY);
	init_image(all->ptr, &all->hud.stamina_bar, BARW, BARH);
	all->wall_gap = 0.0;
	all->stamina = (int)STAMINA_MAX;
	init_textures(all, &all->textures);
	init_data_textures(&all->textures);
	init_stickman(all);
}
