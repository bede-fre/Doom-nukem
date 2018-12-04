/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:12:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/04 15:51:12 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int	ft_color_textures(t_img *ptr, double cpt, int col)
{
	if (col < 0 || col > 64)
		return (ft_rgba(127, 127, 127, 0));
	return (ft_rgba(
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 2],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 1],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl)],
		ptr->data[col * 4 + ((int)(CAM_HEIGHT + cpt) * ptr->sl) + 3]));
}

int			ft_find_color3(t_all *all, double cpt, double col)
{
	return (ft_color_textures(&all->sprites.spr_barrel, cpt, col));
}

int			ft_find_color2(t_all *all, double cpt, int col, float door)
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

int			ft_find_color(t_all *all, double cpt, int col)
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
