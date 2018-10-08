/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:29:03 by toliver           #+#    #+#             */
/*   Updated: 2018/10/08 16:40:03 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

int				ft_printvector(t_vec a)
{
	printf("x = %f, y = %f, z = %f\n", a.x, a.y, a.z);
	return (1);
}

t_line			ft_linedef(t_vec a, t_vec b)
{
	t_line	c;

	c.a = a;
	c.b = b;
	c.slope = ft_2dslope(c.a, c.b);
	c.offset = (c.slope != INFINITY) ? ft_findoffset(c.a, c.slope) : c.a.x;
//	printf("slope = %f, offset = %f\n", c.slope, c.offset);
	c.avalue = c.b.y - c.a.y;
	c.bvalue = c.a.x - c.b.x;
	c.cvalue = c.avalue * c.a.x + c.bvalue * c.a.y;
//	printf("a = %f, b = %f\n", c.avalue, c.bvalue);
//	printf("c = %f\n", c.cvalue);
	return (c);
}

float			ft_2dslope(t_vec a, t_vec b)
{
	if (b.x != a.x)
		return ((b.y - a.y) / (b.x - a.x));
	return (INFINITY); // que return si la division est egale a 0 ?
}

float			ft_findoffset(t_vec a, float slope)
{
	return (a.y - (slope * a.x));
}

t_vec			ft_2dintersection(t_line a, t_line b)
{
	float	x;
	float	y;

	x = (a.avalue * b.bvalue - b.avalue * a.bvalue == 0) ? INFINITY :
		((b.bvalue * a.cvalue - a.bvalue * b.cvalue) /
		(a.avalue * b.bvalue - b.avalue * a.bvalue));
//	printf("x crossing = %f\n", x);
	y = (a.avalue * b.bvalue - b.avalue * a.bvalue == 0) ? INFINITY :
		((a.avalue * b.cvalue - b.avalue * a.cvalue) /
		(a.avalue * b.bvalue - b.avalue * a.bvalue));
//	printf("y crossing = %f\n", y);
	return (ft_vecdef(x, y, 0));
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
		inter.y = (l1.slope == INFINITY) ? l2.slope * inter.x + l2.offset : l1.slope * inter.x + l1.offset;
	inter.z = 0.0;
	return (inter);
}
