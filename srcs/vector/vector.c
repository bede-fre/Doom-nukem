/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:40:01 by toliver           #+#    #+#             */
/*   Updated: 2018/10/09 16:14:51 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec	ft_vecdef(float x, float y, float z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec	ft_vecadd(t_vec a, t_vec b)
{
	t_vec	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vec	ft_vecsub(t_vec a, t_vec b)
{
	t_vec	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}

float	ft_vecnorm(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec	ft_vecnormalize(t_vec a)
{
	t_vec	v;
	float	norm;

	if ((norm = ft_vecnorm(a)) != 1.0 && norm != 0.0)
	{
		v.x = a.x / norm;
		v.y = a.y / norm;
		v.z = a.z / norm;
		return (v);
	}
	return (a);
}
