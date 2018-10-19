/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:04:58 by toliver           #+#    #+#             */
/*   Updated: 2018/10/19 09:35:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	ft_degtorad(float angle)
{
	return (angle / 180.0f * (float)M_PI);
}

float	ft_radtodeg(float angle)
{
	return (angle * 180.0f / (float)M_PI);
}
