/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:40:01 by toliver           #+#    #+#             */
/*   Updated: 2018/09/18 14:13:28 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float		ft_degtorad(float angle)
{
	return (angle / 180.0 * M_PI);
}

float		ft_radtodeg(float angle)
{
	return (angle * 180 / M_PI);
}

t_vec		ft_vecdef(float x, float y, float z)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec		ft_vecadd(t_vec a, t_vec b)
{
	t_vec	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vec		ft_vecsub(t_vec a, t_vec b)
{
	t_vec	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}
