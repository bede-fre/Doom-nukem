/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:26:21 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/05 13:53:06 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void		stock_infos(t_vertex *vertex, t_point p, int num)
{
	vertex->p.x = p.x;
	vertex->p.y = p.y;
	vertex->num = num;
}

t_vertex	*new_vertex(t_sector *sector)
{
	t_sector *tmp_s;
	t_vertex *tmp_v;

	tmp_s = sector;
	while (tmp_s->next)
		tmp_s = tmp_s->next;
	if (!tmp_s->vertex)
	{
		tmp_s->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
		return (tmp_s->vertex);
	}
	tmp_v = tmp_s->vertex;
	while (tmp_v->next)
		tmp_v = tmp_v->next;
	tmp_v->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
	return (tmp_v->next);
}

void		new_sector(t_sector *sector, int num)
{
	t_sector *tmp;
	t_sector *prev_tmp;

	prev_tmp = NULL;
	tmp = sector;
	while (tmp->next)
	{
		prev_tmp = tmp;
		tmp = tmp->next;
	}
	tmp->next = (t_sector*)ft_memalloc(sizeof(t_sector));
	tmp = tmp->next;
	tmp->prev = prev_tmp;
	tmp->num = num;
	tmp->next = NULL;
}

int			check_point(t_sector *sector, t_point p)
{
	t_sector	*tmp_s;
	t_vertex	*tmp_v;

	tmp_s = sector;
	while (tmp_s->next)
		tmp_s = tmp_s->next;
	tmp_v = tmp_s->vertex;
	while (tmp_v)
	{
		if (tmp_v->p.x == p.x && tmp_v->p.y == p.y)
			return (0);
		tmp_v = tmp_v->next;
	}
	return (1);
}

void		make_circular(t_sector *sector)
{
	t_sector	*tmp_s;
	t_vertex	*tmp_v;
	t_vertex	*save_first;

	tmp_s = sector;
	while (tmp_s->next)
		tmp_s = tmp_s->next;
	tmp_v = tmp_s->vertex;
	save_first = tmp_s->vertex;
	while (tmp_v->next)
		tmp_v = tmp_v->next;
	tmp_v->next = save_first;
}

/*
** STOCKAGE INFORMATIONS SECTORS ET VERTEX
*/

void		stock_map(t_env *env)
{
	if (env->actual_vert == 0)
		env->save_p = ft_pointdef(env->mouse.x, env->mouse.y);
	if (env->actual_vert > 2 &&
		env->mouse.x == env->save_p.x && env->mouse.y == env->save_p.y)
	{
		make_circular(env->sector);
		new_sector(env->sector, ++env->actual_sec);
		env->actual_vert = 0;
	}
	else if ((env->actual_vert == 0 ||
		(env->mouse.x != env->save_p.x || env->mouse.y != env->save_p.y))
		&& check_point(env->sector, env->mouse))
		stock_infos(new_vertex(env->sector),
			ft_pointdef(env->mouse.x, env->mouse.y), env->actual_vert++);
}
