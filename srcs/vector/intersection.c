/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:29:03 by toliver           #+#    #+#             */
/*   Updated: 2018/10/09 11:56:51 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

static float	ft_2dslope(t_vec a, t_vec b)
{
	if (b.x != a.x)
		return ((b.y - a.y) / (b.x - a.x));
	return (INFINITY);
}

static float	ft_findoffset(t_vec a, float slope)
{
	return (a.y - (slope * a.x));
}

static t_line	ft_vec_to_line(t_vec a, t_vec b)
{
	t_line l;

	l.a = a;
	l.b = b;
	l.slope = ft_2dslope(a, b);
	l.offset = ft_findoffset(a, l.slope);
	return (l);
}

t_vec			ft_vec_intersection(t_vec uni1, t_vec p1, t_vec uni2, t_vec p2)
{
	t_line	l1;
	t_line	l2;
	t_vec	inter;

	l1 = ft_vec_to_line(ft_vecadd(uni1, p1), p1);
	l2 = ft_vec_to_line(ft_vecadd(uni2, p2), p2);
	if (l1.slope == l2.slope)
		return (ft_vecdef(INFINITY, INFINITY, 0.0));
	if (l1.slope == INFINITY)
		inter.x = l1.a.x;
	else if (l2.slope == INFINITY)
		inter.x = l2.a.x;
	else
		inter.x = (l2.offset - l1.offset) / (l1.slope - l2.slope);
	if (l1.slope == 0.0)
		inter.y = l1.a.y;
	else if (l2.slope == 0.0)
		inter.y = l2.a.y;
	else
		inter.y = (l1.slope == INFINITY) ? l2.slope * inter.x + l2.offset :
			l1.slope * inter.x + l1.offset;
	inter.z = 0.0;
	return (inter);
}
