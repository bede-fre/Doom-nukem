/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:10:13 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/27 14:10:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_mat3	ft_vecrotx(t_mat3 v, double a)
{
	t_mat3	w;
	double	y;
	double	z;

	y = v.y;
	z = v.z;
	w.x = v.x;
	w.y = y * cos(a) - z * sin(a);
	w.z = y * sin(a) + z * cos(a);
	return (w);
}

t_mat3	ft_vecroty(t_mat3 v, double a)
{
	t_mat3	w;
	double	x;
	double	z;

	x = v.x;
	z = v.z;
	w.x = x * cos(a) + z * sin(a);
	w.y = v.y;
	w.z = -x * sin(a) + z * cos(a);
	return (w);
}

t_mat3	ft_vecrotz(t_mat3 v, double a)
{
	t_mat3	w;
	double	x;
	double	y;

	x = v.x;
	y = v.y;
	w.x = x * cos(a) - y * sin(a);
	w.y = x * sin(a) + y * cos(a);
	w.z = v.z;
	return (w);
}

t_mat3	ft_vecrot(t_mat3 a, double xrot, double yrot, double zrot)
{
	t_mat3	v;

	v = ft_vecrotz(a, zrot);
	v = ft_vecroty(v, yrot);
	v = ft_vecrotx(v, xrot);
	return (v);
}
