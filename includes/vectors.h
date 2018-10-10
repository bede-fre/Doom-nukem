/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:33:10 by toliver           #+#    #+#             */
/*   Updated: 2018/10/10 14:12:41 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>
# include <stdio.h>

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

typedef struct	s_line
{
	float		slope;
	float		offset;
	t_vec		a;
	t_vec		b;
}				t_line;

int				ft_printvector(t_vec a);
float			ft_vecnorm(t_vec a);
float			ft_2dvecnorm(t_vec a);
float			ft_degtorad(float angle);
float			ft_radtodeg(float angle);
float			ft_vec_angle(t_vec a, t_vec b);
float			ft_dot_product(t_vec a, t_vec b);
t_vec			ft_vecnormalize(t_vec a);
t_vec			ft_vecdiv(t_vec a, float s);
t_vec			ft_vecadd(t_vec a, t_vec b);
t_vec			ft_vecsub(t_vec a, t_vec b);
t_vec			ft_vecscale(t_vec a, float s);
t_vec			ft_vecrotx(t_vec a, float xrot);
t_vec			ft_vecroty(t_vec a, float yrot);
t_vec			ft_vecrotz(t_vec a, float zrot);
t_vec			ft_cross_product(t_vec a, t_vec b);
t_vec			ft_vecdef(float x, float y, float z);
t_vec			ft_vec_intersection(t_line l1, t_line l2);
t_vec			ft_vecrot(t_vec a, float xrot, float yrot, float zrot);
t_line			ft_vec_to_line(t_vec a, t_vec b);

#endif
