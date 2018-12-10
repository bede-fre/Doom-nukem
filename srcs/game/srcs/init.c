/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:22:58 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 12:16:45 by lguiller         ###   ########.fr       */
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
}

static void	init_textures(t_all *all, t_textures *textures)
{
	init_xpm(all->ptr, &textures->img_n, TEXT_NORTH);
	init_xpm(all->ptr, &textures->img_s, TEXT_SOUTH);
	init_xpm(all->ptr, &textures->img_e, TEXT_EAST);
	init_xpm(all->ptr, &textures->img_w, TEXT_WEST);
	init_xpm(all->ptr, &textures->img_d, TEXT_DOOR);
	init_xpm(all->ptr, &textures->img_dr, TEXT_DOOR_R);
	init_xpm(all->ptr, &textures->nether, TEXT_NETHER);
	init_xpm(all->ptr, &all->sprites.barrel, SPR_BARREL);
	init_xpm(all->ptr, &all->sprites.ennemy, SPR_ENNEMY);
	init_xpm(all->ptr, &all->sprites.lightning, SPR_LIGHTNING);
	init_xpm(all->ptr, &all->sprites.jetpack, SPR_JETPACK);
	init_xpm(all->ptr, &all->sprites.girl_face, GIRL_FACE);
	init_xpm(all->ptr, &all->sprites.girl_left, GIRL_LEFT);
	init_xpm(all->ptr, &all->sprites.girl_right, GIRL_RIGHT);
	init_xpm(all->ptr, &all->sprites.girl_back, GIRL_BACK);
}

static void	init_hud(t_all *all, t_hud *hud)
{
	t_img tmp;

	init_xpm(all->ptr, &hud->s_jump, SPR_JUMP);
	init_xpm(all->ptr, &hud->s_run, SPR_RUN);
	init_xpm(all->ptr, &hud->s_idle, SPR_IDLE);
	init_xpm(all->ptr, &hud->s_walk, SPR_WALK);
	init_xpm(all->ptr, &hud->s_crouch, SPR_CROUCH);
	init_xpm(all->ptr, &hud->mute, MUTE_IMG);
	init_image(all->ptr, &hud->stamina_bar, BARW, BARH);
	init_xpm(all->ptr, &tmp, END_IMG);
	scale_img(&all->end_img, &tmp);
	init_xpm(all->ptr, &tmp, SPR_JETPACK_BIG);
	scale_img(&all->hud.jetpack, &tmp);
}

void		ft_init(t_all *all, char *title)
{
	all->ptr.mlx = mlx_init();
	all->ptr.win = mlx_new_window(all->ptr.mlx, WINX, WINY, title);
	init_image(all->ptr, &all->info, INFOX, INFOY);
	init_image(all->ptr, &all->fp, WINX, WINY);
	init_image(all->ptr, &all->end_img, WINX, WINY);
	init_image(all->ptr, &all->hud.jetpack, 32, 32);
	init_textures(all, &all->textures);
	init_hud(all, &all->hud);
	all->wall_gap = 0.0;
	all->p.ray_infos = 0;
	all->jetpack = 0;
	all->girl_vec = ft_vecdef(1.0, 0.0, 0.0);
	all->stamina = (int)STAMINA_MAX;
}
