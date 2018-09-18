/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:40:23 by toliver           #+#    #+#             */
/*   Updated: 2018/09/18 17:16:27 by toliver          ###   ########.fr       */
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
float		ft_vecnorm(t_vec a);
t_vec		ft_vecnormalize(t_vec a);
t_vec		ft_vecscale(t_vec a, float s);
t_vec		ft_vecdiv(t_vec a, float s);
t_vec		ft_vecrotx(t_vec a, float xrot);
t_vec		ft_vecroty(t_vec a, float yrot);
t_vec		ft_vecrotz(t_vec a, float zrot);
t_vec		ft_vecrot(t_vec a, float xrot, float yrot, float zrot);

#endif
