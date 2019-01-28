/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:51:47 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/20 16:11:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_mat3	ft_vecscale(t_mat3 a, double s)
{
	t_mat3	v;

	v.x = a.x * s;
	v.y = a.y * s;
	v.z = a.z * s;
	return (v);
}

t_mat3	ft_vecdiv(t_mat3 a, double s)
{
	t_mat3	v;

	if (s != 0.0f)
	{
		v.x = a.x / s;
		v.y = a.y / s;
		v.z = a.z / s;
		return (v);
	}
	return (a);
}

t_mat3	ft_cross_product(t_mat3 a, t_mat3 b)
{
	t_mat3	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}
