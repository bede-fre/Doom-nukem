/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/03 12:03:39 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		ft_color_textures(t_img *ptr, double cpt, int col)
{
	if (col < 0 || col > 64)
		return (ft_rgba(127, 127, 127, 0));
	return (ft_rgba(
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 2],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 1],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl)],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 3]));
}

static int		ft_find_color2(t_all *all, double cpt, int col, float door)
{
	float	hit_wall;

	hit_wall = all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)];
	if (hit_wall == T_DOOR_C && (all->rc.ray.hit == S_W ||
		all->rc.ray.hit == E_W))
		return (ft_color_textures(&all->textures.img_d, cpt, col));
	else if ((hit_wall == T_DOOR_I || hit_wall == T_DOOR_R) &&
		(all->rc.ray.hit == N_W || all->rc.ray.hit == W_W))
		return (ft_color_textures(&all->textures.img_dr, cpt, col + door));
	else if ((hit_wall == T_DOOR_I || hit_wall == T_DOOR_R) &&
		(all->rc.ray.hit == S_W || all->rc.ray.hit == E_W))
		return (ft_color_textures(&all->textures.img_d, cpt, col - door));
	else if (hit_wall == T_DOOR_I && (all->rc.ray.hit == N_W ||
		all->rc.ray.hit == W_W))
		return (ft_color_textures(&all->textures.img_dr, cpt, col));
	else if (hit_wall == TP_S)
		return (ft_color_textures(&all->textures.nether, cpt, col));
	else
		return (ft_color_textures(&all->textures.img_d, cpt, col));
}

static int		ft_find_color(t_all *all, double cpt, int col)
{
	char	hit_wall;
	float	door;

	hit_wall = all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)];
	door = 64 * door_timer(0.0, to_map(all->rc.ray.y), to_map(all->rc.ray.x),
		all->rc.map);
	if (hit_wall == T_A || hit_wall == T_AS)
		return (ft_color_textures(&all->textures.img_n, cpt, col));
	else if (hit_wall == T_B || hit_wall == T_BS)
		return (ft_color_textures(&all->textures.img_e, cpt, col));
	else if (hit_wall == T_C || hit_wall == T_CS)
		return (ft_color_textures(&all->textures.img_s, cpt, col));
	else if (hit_wall == T_D || hit_wall == T_DS)
		return (ft_color_textures(&all->textures.img_w, cpt, col));
	else if (hit_wall == T_DOOR_C && (all->rc.ray.hit == N_W ||
		all->rc.ray.hit == W_W))
		return (ft_color_textures(&all->textures.img_dr, cpt, col));
	else
		return (ft_find_color2(all, cpt, col, door));
}

static int		find_color3(t_all *all, double cpt, double col)
{
	return (ft_color_textures(&all->sprites.spr_barrel, cpt, col));
}

static void		ft_print_textures(t_all *all, int x, int i, double h)
{
	int		col;
	double	cpt;

	cpt = ((double)i - (all->start_wall - ((h / 4.0) * (2.0 + all->wall_gap))))
		* (BLOCK_SIZE / h) - (BLOCK_SIZE / 2.0);
	if (all->rc.ray.hit == N_W || all->rc.ray.hit == S_W)
		col = (int)(all->rc.ray.x - ft_roundminf(all->rc.ray.x, BLOCK_SIZE));
	else
		col = (int)(all->rc.ray.y - ft_roundminf(all->rc.ray.y, BLOCK_SIZE));
	ft_fill_pixel(&all->fp, x, i, ft_find_color(all, cpt, col));
}

static void		ft_print_sprite(t_all *all, int x, int i, double h)
{
	double			cpt;
	double			col;
	const t_mat3	player = ft_vecdef(all->p.x, all->p.y, 0.0);
	const t_mat3	v_sprite = ft_vecsub(all->rc.ray.sprite, player);
	const t_mat3	v_inter = ft_vecsub(all->rc.ray.inter, player);
	t_mat3			begin;
	t_mat3			end;

	begin = ft_vecadd(ft_vecscale(ft_vecrotz(ft_vecnormalize(v_sprite), -90.0), BLOCK_SIZE / 2.0), v_sprite);
	end = ft_vecscale(ft_vecnormalize(v_inter), ft_vecnorm(v_sprite) / cos(ft_rad(ft_vecangle(v_sprite, v_inter))));
	col = ft_vecnorm(ft_vecsub(end, begin));
	cpt = ((double)i - (all->start_wall - ((h / 4.0) * (2.0 + all->wall_gap))))
		* (BLOCK_SIZE / h) - (BLOCK_SIZE / 2.0);
	if (find_color3(all, cpt, col) != (int)ALPHA && col >= 0.0 && col < 64.0)
		ft_fill_pixel(&all->fp, x, i, find_color3(all, cpt, col));
}


static void		print_sprite(t_all *all, int x)
{
	int				i;
	const double	h = ft_wall_height_on_screen(
	ft_vecnorm(ft_vecsub(all->rc.ray.sprite, ft_vecdef(all->p.x, all->p.y, 0.0))));
	const int		start = all->start_wall - ((h / 4.0) * (2.0 + all->wall_gap));

	i = -1;
	while (++i < h)
		ft_print_sprite(all, x, i + start, h);
}

void			ft_print_on_screen(t_all *all, int x, double lens)
{
	int		i;
	double	h;

	i = -1;
	h = ft_wall_height_on_screen(all->rc.ray.dist * cos(lens)) / 4.0;
	if (all->rc.ray.x < 0.0 || all->rc.ray.x >= (MAPX * BLOCK_SIZE)
		|| all->rc.ray.y < 0.0 || all->rc.ray.y >= (MAPY * BLOCK_SIZE))
		h = 0.0;
	while (++i < WINY)
	{
		if ((double)i <= (all->start_wall - (h * (2.0 + all->wall_gap))))
			ft_fill_pixel(&all->fp, x, i, TOP);
		else if ((double)i >= (all->start_wall + (h * (2.0 - all->wall_gap))))
			ft_fill_pixel(&all->fp, x, i, BOTTOM);
		else
			ft_print_textures(all, x, i, h * 4.0);
	}
	if (all->rc.ray.test)
		print_sprite(all, x);
}
