/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:36:49 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/16 13:37:33 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		cpy_link(t_wall *w1, t_wall *w2)
{
	w1->num = w2->num;
	w1->nextzone = w2->nextzone;
	w1->origin = w2->origin;
}

static void		swap_link(t_wall *w1, t_wall *w2)
{
	t_wall *tmp;

	tmp = (t_wall*)ft_memalloc(sizeof(t_wall));
	cpy_link(tmp, w1);
	cpy_link(w1, w2);
	cpy_link(w2, tmp);
	free(tmp);
}

void			sort_list(t_zone *zone)
{
	t_zone *tmp_z;
	t_wall *tmp_w;
	t_wall *tmp_w2;

	tmp_z = zone;
	while (tmp_z)
	{
		tmp_w = tmp_z->wall;
		while (tmp_w)
		{
			tmp_w2 = tmp_z->wall;
			while (tmp_w2->next)
			{
				if (tmp_w2->num > tmp_w2->next->num)
					swap_link(tmp_w2, tmp_w2->next);
				tmp_w2 = tmp_w2->next;
			}
			tmp_w = tmp_w->next;
		}
		tmp_z = tmp_z->next;
	}
}
