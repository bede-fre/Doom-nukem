/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 13:55:10 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/20 16:11:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

double	ft_vecangle(t_mat3 a, t_mat3 b)
{
	return (ft_todeg(acosf(ft_dot_product(a, b) /
		(ft_vecnorm(a) * ft_vecnorm(b)))));
}
