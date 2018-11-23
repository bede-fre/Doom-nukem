/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/21 16:28:29 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	ft_moving(t_all *all, double dir)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (cos(all->p.a) >= 0.0) ? dir * HIT_BOX : -dir * HIT_BOX;
	sh.y = (sin(all->p.a) >= 0.0) ? -dir * HIT_BOX : dir * HIT_BOX;
	p.x = (sh.x + all->p.x + dir * ((cos(all->p.a) * all->speed)));
	p.y = (sh.y + all->p.y + -dir * ((sin(all->p.a) * all->speed)));
	all->p.x += (all->p.y >= 0.0 && to_map(all->p.y) < 32.0
		&& p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX)
		&& !is_wall(all->rc.map[to_map((all->p.y - HIT_BOX))][to_map(p.x)])
		&& !is_wall(all->rc.map[to_map((all->p.y + HIT_BOX))][to_map(p.x)])) ?
		dir * (cos(all->p.a) * all->speed) : 0.0;
	all->p.y += (all->p.x >= 0.0 && to_map(all->p.x) < 32.0
		&& p.y >= HIT_BOX && p.y < (MAPY * (int)BLOCK_SIZE - HIT_BOX)
		&& !is_wall(all->rc.map[to_map(p.y)][to_map((all->p.x + HIT_BOX))])
		&& !is_wall(all->rc.map[to_map(p.y)][to_map((all->p.x - HIT_BOX))])) ?
		-dir * (sin(all->p.a) * all->speed) : 0.0;
}

static void	ft_strafing(t_all *all, double dir)
{
	t_coord		p;
	t_fcoord	sh;

	sh.x = (sin(all->p.a) >= 0.0) ? -dir * HIT_BOX : dir * HIT_BOX;
	sh.y = (cos(all->p.a) >= 0.0) ? -dir * HIT_BOX : dir * HIT_BOX;
	p.x = (sh.x + all->p.x + -dir * (sin(all->p.a) * all->speed));
	p.y = (sh.y + all->p.y + -dir * (cos(all->p.a) * all->speed));
	all->p.x += (all->p.y >= 0.0 && to_map(all->p.y) < 32.0
		&& p.x >= HIT_BOX && p.x < (MAPX * (int)BLOCK_SIZE - HIT_BOX)
		&& !is_wall(all->rc.map[to_map((all->p.y - HIT_BOX))][to_map(p.x)])
		&& !is_wall(all->rc.map[to_map((all->p.y + HIT_BOX))][to_map(p.x)])) ?
		-dir * (sin(all->p.a) * all->speed) : 0.0;
	all->p.y += (all->p.x >= 0.0 && to_map(all->p.x) < 32.0
		&& p.y >= HIT_BOX && p.y < (MAPY * (int)BLOCK_SIZE - HIT_BOX)
		&& !is_wall(all->rc.map[to_map(p.y)][to_map((all->p.x + HIT_BOX))])
		&& !is_wall(all->rc.map[to_map(p.y)][to_map((all->p.x - HIT_BOX))])) ?
		-dir * (cos(all->p.a) * all->speed) : 0.0;
}

static void	ft_teleport(t_all *all)
{
	int	y;
	int	x;

	if (all->rc.map[to_map(all->p.y)][to_map(all->p.x)] == '3')
	{
		y = -1;
		while (++y < MAPY)
		{
			x = -1;
			while (++x < MAPX)
			{
				if (all->rc.map[y][x] == '4')
				{
					all->p.x = x * (int)BLOCK_SIZE + 32;
					all->p.y = y * (int)BLOCK_SIZE + 32;
				}
			}
		}
	}
}

static void	ft_refresh_images(t_all *all)
{
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->fp.img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->info.img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->sprites.knife,
		WINX / 2, WINY - 239);
}

int			ft_movements(t_all *all)
{
	if (all->keys_tab[KEY_CTRL] == TRUE)
		all->speed = CROUCH_SPEED;
	else if (all->keys_tab[KEY_SHIFT] == TRUE && all->keys_tab[KEY_W] == TRUE)
		all->speed = RUN_SPEED;
	else
		all->speed = MOVE_SPEED;
	(all->keys_tab[KEY_A] == TRUE) ? ft_strafing(all, 1.0) : 0;
	(all->keys_tab[KEY_D] == TRUE) ? ft_strafing(all, -1.0) : 0;
	(all->keys_tab[KEY_W] == TRUE) ? ft_moving(all, 1.0) : 0;
	(all->keys_tab[KEY_S] == TRUE) ? ft_moving(all, -1.0) : 0;
	(all->keys_tab[KEY_Q] == TRUE) ? all->p.a += ft_rad(ROT_SPEED) : 0;
	(all->keys_tab[KEY_E] == TRUE) ? all->p.a -= ft_rad(ROT_SPEED) : 0;
	(all->keys_tab[KEY_F] == TRUE) ? door_open(all) : 0;
	all->skip = (all->keys_tab[KEY_ENTER] == TRUE) ? 1 : 0;
	jump_and_crouch(all);
	ft_teleport(all);
	mlx_destroy_image(all->ptr.mlx, all->info.img);
	all->info.img = mlx_new_image(all->ptr.mlx, INFOX, INFOY);
	all->info.data = mlx_get_data_addr(all->info.img, &all->info.bpp,
		&all->info.sl, &all->info.endian);
	ft_print_all(all);
	ft_refresh_images(all);
	return (1);
}
