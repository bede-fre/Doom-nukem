/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:39:59 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/23 13:42:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

static float	ft_2dslope(t_mat3 a, t_mat3 b)
{
	if (b.x != a.x)
		return ((b.y - a.y) / (b.x - a.x));
	return (INFINITY);
}

static float	ft_findoffset(t_mat3 a, float slope)
{
	return (a.y - (slope * a.x));
}

t_line			ft_mat3_to_line(t_mat3 a, t_mat3 b)
{
	t_line l;

	l.a = a;
	l.b = b;
	l.slope = ft_2dslope(a, b);
	l.offset = ft_findoffset(a, l.slope);
	return (l);
}

t_mat3			ft_mat3_intersection(t_line l1, t_line l2)
{
	t_mat3	inter;

	if (l1.slope == l2.slope)
		return (ft_vecdef(INFINITY, INFINITY, 0.0f));
	if (l1.slope == INFINITY)
		inter.x = l1.a.x;
	else if (l2.slope == INFINITY)
		inter.x = l2.a.x;
	else
		inter.x = (l2.offset - l1.offset) / (l1.slope - l2.slope);
	if (l1.slope == 0.0f)
		inter.y = l1.a.y;
	else if (l2.slope == 0.0f)
		inter.y = l2.a.y;
	else
		inter.y = (l1.slope == INFINITY) ? l2.slope * inter.x + l2.offset :
			l1.slope * inter.x + l1.offset;
	inter.z = 0.0f;
	return (inter);
}
