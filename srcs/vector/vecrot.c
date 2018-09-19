/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecrot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:05:41 by toliver           #+#    #+#             */
/*   Updated: 2018/09/19 15:06:18 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

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
