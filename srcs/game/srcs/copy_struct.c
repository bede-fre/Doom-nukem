/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:11:56 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/10 12:16:10 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_cpy_struct(t_all *tmp, t_all *all)
{
	int	i;

	i = -1;
	while (++i < KEYS_TAB_SIZE)
		tmp->keys_tab[i] = all->keys_tab[i];
	tmp->textures = all->textures;
	tmp->hud = all->hud;
	tmp->info = all->info;
	tmp->ptr = all->ptr;
	tmp->fp = all->fp;
	tmp->rc = all->rc;
	tmp->sprites = all->sprites;
	tmp->p = all->p;
	tmp->a = all->a;
	tmp->i = all->i;
	tmp->lens = all->lens;
	tmp->prevx = all->prevx;
	tmp->prevy = all->prevy;
	tmp->start_wall = all->start_wall;
	tmp->wall_gap = all->wall_gap;
	tmp->rc.ray = all->rc.ray;
	tmp->rc.ray.sprite = all->rc.ray.sprite;
	tmp->rc.ray.sprite.x = all->rc.ray.sprite.x;
	tmp->rc.ray.sprite.y = all->rc.ray.sprite.y;
	tmp->girl_vec = all->girl_vec;
}
