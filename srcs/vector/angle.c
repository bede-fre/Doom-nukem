/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:04:58 by toliver           #+#    #+#             */
/*   Updated: 2018/09/19 15:05:32 by toliver          ###   ########.fr       */
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
