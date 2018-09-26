/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 16:29:03 by toliver           #+#    #+#             */
/*   Updated: 2018/09/26 09:25:26 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

int			ft_printvector(t_vec a)
{
	printf("x = %f, y = %f, z = %f\n", a.x, a.y, a.z);
	return (1);
}

t_line		ft_linedef(t_vec a, t_vec b)
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

float		ft_2dslope(t_vec a, t_vec b)
{
	if (b.x - a.x != 0)
		return ((b.y - a.y) / (b.x - a.x));
	return (INFINITY); // que return si la division est egale a 0 ?
}

float		ft_findoffset(t_vec a, float slope)
{
	return (a.y - (slope * a.x));
}

t_vec		ft_2dintersection(t_line a, t_line b)
{
	float	x;
	float	y;

	x = (a.avalue * b.bvalue - b.avalue * a.bvalue == 0) ? INFINITY :
		((b.bvalue * a.cvalue - a.bvalue * b.cvalue) /
		(a.avalue * b.bvalue - b.avalue * a.bvalue));
	printf("x crossing = %f\n", x);
	y = (a.avalue * b.bvalue - b.avalue * a.bvalue == 0) ? INFINITY :
		((a.avalue * b.cvalue - b.avalue * a.cvalue) /
		(a.avalue * b.bvalue - b.avalue * a.bvalue));
	printf("y crossing = %f\n", y);
	return (ft_vecdef(x, y, 0));
}
