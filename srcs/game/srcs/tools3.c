/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:12:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 12:08:26 by lguiller         ###   ########.fr       */
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

static int	ft_find_color4(t_all *all, double cpt, double col, double angle)
{
	if (angle < 45.0 && angle > -45.0)
		return (ft_color_textures(&all->sprites.girl_face, cpt, col));
	else if (angle < 135.0 && angle > -135.0)
	{
		if (angle >= 0)
			return (ft_color_textures(&all->sprites.girl_left, cpt, col));
		else
			return (ft_color_textures(&all->sprites.girl_right, cpt, col));
	}
	else
		return (ft_color_textures(&all->sprites.girl_back, cpt, col));
}

int			ft_find_color3(t_all *all, double cpt, double col, double angle)
{
	char	hit_wall;

	hit_wall = all->rc.map[to_map(all->var.tp.y)][to_map(all->var.tp.x)];
	if (hit_wall == BARREL)
		return (ft_color_textures(&all->sprites.barrel, cpt, col));
	else if (hit_wall == ENNEMY)
		return (ft_color_textures(&all->sprites.ennemy, cpt, col));
	else if (hit_wall == LIGHTNING)
		return (ft_color_textures(&all->sprites.lightning, cpt, col));
	else if (hit_wall == JETPACK)
		return (ft_color_textures(&all->sprites.jetpack, cpt, col));
	else if (hit_wall == GIRL)
		return (ft_find_color4(all, cpt, col, angle));
	else
		return (0);
}

int			ft_find_color2(t_all *all, double cpt, int col, float door)
{
	float	hit_wall;

	hit_wall = all->rc.map[to_map(all->rc.ray.y)][to_map(all->rc.ray.x)];
	if (hit_wall == DOOR_C && (all->rc.ray.hit == S_W ||
		all->rc.ray.hit == E_W))
		return (ft_color_textures(&all->textures.img_d, cpt, col));
	else if ((hit_wall == DOOR_I || hit_wall == DOOR_R) &&
		(all->rc.ray.hit == N_W || all->rc.ray.hit == W_W))
		return (ft_color_textures(&all->textures.img_dr, cpt, col + door));
	else if ((hit_wall == DOOR_I || hit_wall == DOOR_R) &&
		(all->rc.ray.hit == S_W || all->rc.ray.hit == E_W))
		return (ft_color_textures(&all->textures.img_d, cpt, col - door));
	else if (hit_wall == DOOR_I && (all->rc.ray.hit == N_W ||
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
	if (hit_wall == WOOD || hit_wall == WOOD_S)
		return (ft_color_textures(&all->textures.img_n, cpt, col));
	else if (hit_wall == METAL || hit_wall == METAL_S)
		return (ft_color_textures(&all->textures.img_e, cpt, col));
	else if (hit_wall == STONE || hit_wall == STONE_S)
		return (ft_color_textures(&all->textures.img_s, cpt, col));
	else if (hit_wall == ICE || hit_wall == ICE_S)
		return (ft_color_textures(&all->textures.img_w, cpt, col));
	else if (hit_wall == DOOR_C && (all->rc.ray.hit == N_W ||
		all->rc.ray.hit == W_W))
		return (ft_color_textures(&all->textures.img_dr, cpt, col));
	else
		return (ft_find_color2(all, cpt, col, door));
}
