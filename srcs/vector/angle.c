/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:04:58 by toliver           #+#    #+#             */
/*   Updated: 2018/10/09 13:57:56 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	ft_degtorad(float angle)
{
	return (angle / 180.0 * M_PI);
}

float	ft_radtodeg(float angle)
{
	return (angle * 180 / M_PI);
}
