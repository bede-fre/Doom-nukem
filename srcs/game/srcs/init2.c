/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:50:26 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/23 13:31:12 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int	find_src_pixel_col(t_img *img, int x, int y)
{
	const int px = x * 4 + y * img->sl;

	return (ft_rgba(img->data[px + 2], img->data[px + 1], img->data[px],
			img->data[px + 3]));
}

void		scale_img(t_img *dst, t_img *src)
{
	double	incx;
	double	incy;
	t_point	p;

	incx = (double)src->width / (double)dst->width;
	incy = (double)src->height / (double)dst->height;
	p.y = -1;
	while (++p.y < dst->height)
	{
		p.x = -1;
		while (++p.x < dst->width)
			ft_fill_pixel(dst, p.x, p.y, find_src_pixel_col(src,
			(int)((double)p.x * incx), (int)((double)p.y * incy)));
	}
}
