/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:40:01 by toliver           #+#    #+#             */
/*   Updated: 2018/09/18 17:27:38 by toliver          ###   ########.fr       */
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

float		ft_vecnorm(t_vec a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_vec		ft_vecnormalize(t_vec a)
{
	t_vec	v;
	float	norm;

	if ((norm = ft_vecnorm(a)) != 1 && norm != 0)
	{
		v.x = a.x / norm;
		v.y = a.y / norm;
		v.z = a.z / norm;
		return (v);
	}
	return (a);
}

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

t_vec		ft_vecrotx(t_vec a, float xrot)
{
	t_vec	v;
	float	cos;
	float	sin;

	while (xrot <= -360)
		xrot += 360;
	while (xrot >= 360)
		xrot -= 360;
	xrot = ft_degtorad(xrot);
	cos = cosf(xrot);
	sin = sinf(xrot);
	v.x = a.x;
	v.y = a.y * cos - a.z * sin;
	v.z = a.y * sin + a.z * cos;
	return (v);
}

t_vec		ft_vecroty(t_vec a, float yrot)
{
	t_vec	v;
	float	cos;
	float	sin;

	while (yrot <= -360)
		yrot += 360;
	while (yrot >= 360)
		yrot -= 360;
	yrot = ft_degtorad(yrot);
	cos = cosf(yrot);
	sin = sinf(yrot);
	v.x = a.x * cos - a.z * sin;
	v.y = a.y;
	v.z = -(a.x) * sin + a.z * cos;
	return (v);
}

t_vec		ft_vecrotz(t_vec a, float zrot)
{
	t_vec	v;
	float	cos;
	float	sin;

	while (zrot <= -360)
		zrot += 360;
	while (zrot >= 360)
		zrot -= 360;
	zrot = ft_degtorad(zrot);
	cos = cosf(zrot);
	sin = sinf(zrot);
	v.x = a.x * cos - a.y * sin;
	v.y = a.x * sin + a.y * cos;
	v.z = a.z;
	return (v);
}

t_vec		ft_vecrot(t_vec a, float xrot, float yrot, float zrot)
{
	t_vec	v;

	v = ft_vecrotz(a, zrot);
	v = ft_vecroty(v, yrot);
	v = ft_vecrotx(v, xrot);
	return (v);
}
