/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:26:21 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/05 15:55:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** MALLOC D'UN NOUVEAU VERTEX A LA FIN DE TOUT LES AUTRES DEJA EXISTANT
*/

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

/*
** MALLOC D'UN NOUVEAU SECTEUR A LA FIN DE TOUT LES AUTRES DEJA EXISTANT
*/

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

/*
** CHECK SI LE NOUVEAU POINT PEUT ETRE ENREGISTRER, IL NE L'ES PAS SI C'EST
** LE MEME QU'UN PRECEDENT
*/

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

/*
** FAIRE POINTER LE DERNIER ELEMENT DE LA LISTE VERS LE PREMIER POUR LA RENDRE
** CIRCULAIRE
*/

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
	t_vertex *tmp;

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
	{
		tmp = new_vertex(env->sector);
		tmp->p.x = env->mouse.x;
		tmp->p.y = env->mouse.y;
		tmp->num = env->actual_vert++;
	}
}
