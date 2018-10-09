/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:01:14 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/09 16:15:55 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	ft_vec_angle(t_vec a, t_vec b)
{
	return (ft_radtodeg(acosf(ft_dot_product(a, b) /
		(ft_vecnorm(a) * ft_vecnorm(b)))));
}
