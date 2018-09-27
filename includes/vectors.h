/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:33:10 by toliver           #+#    #+#             */
/*   Updated: 2018/09/27 16:28:17 by toliver          ###   ########.fr       */
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

typedef struct	s_line
{
	t_vec		a;
	t_vec		b;
	float		slope;
	float		offset;
	float		avalue;
	float		bvalue;
	float		cvalue;
}				t_line;

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

t_vec		ft_2dintersection(t_line a, t_line b);
float		ft_findoffset(t_vec a, float slope);
float		ft_2dslope(t_vec a, t_vec b);
float		ft_2dvecnorm(t_vec a);
t_line		ft_linedef(t_vec a, t_vec b);
int			ft_printvector(t_vec a);
float		ft_dot_product(t_vec a, t_vec b);
float		ft_vec_angle(t_vec a, t_vec b);

#endif
