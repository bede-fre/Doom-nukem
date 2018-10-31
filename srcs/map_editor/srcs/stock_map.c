/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:26:21 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/31 17:22:58 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"


void	stock_vertex(t_env *env)
{
	t_vertex	*tmp_v;
	static int	i;
	
	if (env->sector->num != env->save_s)
		i = 0;
	if (i == 0)
	{
		env->sector->vertex = (t_vertex*)ft_memalloc(sizeof(t_vertex));
		env->sector->vertex->p = ft_pointdef(env->mouse.x, env->mouse.y);
		env->sector->vertex->num = i;
		i = 1;
		env->sector->vertex->next = NULL;
	}
	else
	{
		env->sector->vertex->next = (t_vertex*)ft_memalloc(sizeof(t_vertex));
		tmp_v = env->sector->vertex;
		tmp_v = env->sector->vertex->next;
		tmp_v->p = ft_pointdef(env->mouse.x, env->mouse.y);
		tmp_v->num++;
		tmp_v->next = NULL;
	}
}

/*
** STOCKAGE INFORMATIONS SECTORS ET VERTEX
*/

void	stock_map(t_env *env)
{
	t_sector	*tmp_s;
	static int	i;

	if (i == 0)
	{
		env->sector = (t_sector*)ft_memalloc(sizeof(t_sector));
		env->sector->num = i;
		i = 1;
		env->sector->next = NULL;
		env->sector->prev = NULL;
		env->save_p = ft_pointdef(env->mouse.x, env->mouse.y);
		env->save_s = env->sector->num;
		stock_vertex(env);
	}
	if ((env->mouse.x != env->save_p.x) && (env->mouse.y != env->save_p.y))
		stock_vertex(env);
	else
	{
		env->sector->next = (t_sector*)ft_memalloc(sizeof(t_sector));
		tmp_s = env->sector;
		tmp_s = env->sector->next;
		tmp_s->num++;
		i = 1;
		tmp_s->next = NULL;
		tmp_s->prev = NULL;
		env->save_p = ft_pointdef(env->mouse.x, env->mouse.y);
		stock_vertex(env);
	}
}
