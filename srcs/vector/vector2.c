/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:06:45 by toliver           #+#    #+#             */
/*   Updated: 2018/09/26 09:42:17 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec		ft_vecscale(t_vec a, float s)
{
	t_vec	v;

	v.x = a.x * s;
	v.y = a.y * s;
	v.z = a.z * s;
	return (v);
}

t_vec		ft_vecdiv(t_vec a, float s)
{
	t_vec	v;

	if (s != 0)
	{
		v.x = a.x / s;
		v.y = a.y / s;
		v.z = a.z / s;
		return (v);
	}
	return (a);
}

float		ft_2dvecnorm(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

float		ft_dot_product(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

float		ft_vec_angle(t_vec a, t_vec b)
{
	return (ft_radtodeg(acos(ft_dot_product(a, b) /
					(ft_vecnorm(a) * ft_vecnorm(b)))));
}
