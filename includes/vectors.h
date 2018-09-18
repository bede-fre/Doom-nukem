/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:40:23 by toliver           #+#    #+#             */
/*   Updated: 2018/09/18 15:34:44 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
#define VECTORS_H

#include <math.h>

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

float		ft_degtorad(float angle);
float		ft_radtodeg(float angle);

t_vec		ft_vecdef(float x, float y, float z);
t_vec		ft_vecadd(t_vec a, t_vec b);
t_vec		ft_vecsub(t_vec a, t_vec b);

#endif
