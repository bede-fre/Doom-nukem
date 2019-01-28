/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:42:53 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/20 16:11:03 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_mat3	ft_vecdef(double x, double y, double z)
{
	t_mat3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_mat3	ft_vecadd(t_mat3 a, t_mat3 b)
{
	t_mat3	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_mat3	ft_vecsub(t_mat3 a, t_mat3 b)
{
	t_mat3	v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}
