/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radian_degre_convertion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:00:42 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/23 14:03:20 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

double	ft_torad(double x)
{
	return (x * M_PI / 180.0);
}

double	ft_todeg(double x)
{
	return (x * 180.0 / M_PI);
}
