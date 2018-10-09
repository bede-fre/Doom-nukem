/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:06:45 by toliver           #+#    #+#             */
/*   Updated: 2018/10/09 16:15:15 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec	ft_vecscale(t_vec a, float s)
{
	t_vec	v;

	v.x = a.x * s;
	v.y = a.y * s;
	v.z = a.z * s;
	return (v);
}

t_vec	ft_vecdiv(t_vec a, float s)
{
	t_vec	v;

	if (s != 0.0)
	{
		v.x = a.x / s;
		v.y = a.y / s;
		v.z = a.z / s;
		return (v);
	}
	return (a);
}

float	ft_2dvecnorm(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

float	ft_dot_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	ft_cross_product(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}
