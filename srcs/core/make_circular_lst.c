/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_circular_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:42:39 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/16 13:42:53 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	make_circular_lst(t_zone *zone)
{
	t_zone	*tmp_z;
	t_wall	*tmp_w;

	tmp_z = zone;
	while (tmp_z)
	{
		tmp_w = tmp_z->wall;
		while (tmp_w->next)
			tmp_w = tmp_w->next;
		tmp_w->next = tmp_z->wall;
		tmp_z = tmp_z->next;
	}
}
