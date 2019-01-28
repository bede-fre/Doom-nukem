/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:10:00 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/27 14:10:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

double	ft_vecnorm(t_mat3 a)
{
	return (sqrt(a.x * a.x + a.y * a.y + a.z * a.z));
}

t_mat3	ft_vecnormalize(t_mat3 v)
{
	double	d;

	d = ft_vecnorm(v);
	v.x /= d;
	v.y /= d;
	v.z /= d;
	return (v);
}
