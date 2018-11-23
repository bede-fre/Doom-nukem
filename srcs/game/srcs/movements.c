/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:24:19 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/23 16:33:10 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_moving(t_all *all, double dir)
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

void		ft_strafing(t_all *all, double dir)
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

	if (all->rc.map[to_map(all->p.y)][to_map(all->p.x)] == 'e')
		all->end = 1;
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
					Mix_PlayChannel(-1, all->sounds.teleport, 0);
				}
			}
		}
	}
}

static void	ft_refresh_images(t_all *all)
{
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->fp.img, 0, 0);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->info.img, 0, 0);
	print_stamina_bar(&all->hud.stamina_bar, all->stamina);
	mlx_put_image_to_window(all->ptr.mlx, all->ptr.win,
		all->hud.stamina_bar.img, BARX, BARY);
	if (all->s_jump && all->stamina > JUMP_STA)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->hud.s_jump.ptr,
		INFOX / 2, WINY - 85);
	else if (all->s_idle)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->hud.s_idle.ptr,
		INFOX / 2, WINY - 85);
	else if (all->speed == RUN_SPEED)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->hud.s_run.ptr,
		INFOY / 2, WINY - 85);
	else if (all->speed == MOVE_SPEED)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win, all->hud.s_walk.ptr,
		INFOX / 2, WINY - 85);
	else if (all->speed == CROUCH_SPEED)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win,
		all->hud.s_crouch.ptr, INFOX / 2, WINY - 85);
	if (all->end)
		mlx_put_image_to_window(all->ptr.mlx, all->ptr.win,
			all->end_img.img, 0, 0);
}

int			ft_movements(t_all *all)
{
	refresh_events(all);
	jump_and_crouch(all);
	ft_teleport(all);
	stamina_control(all);
	mlx_destroy_image(all->ptr.mlx, all->info.img);
	init_image(all->ptr, &all->info, INFOX, INFOY);
	ft_print_all(all);
	ft_refresh_images(all);
	return (1);
}
