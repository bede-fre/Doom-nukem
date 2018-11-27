/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:04:13 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/27 11:05:35 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			ft_wall_height_on_screen(double dist)
{
	return ((int)((((double)WINX / 2.0) / tan(ft_rad(FOV / 2.0))
		* (CAM_HEIGHT) / dist) * 2.0));
}

int			is_movement(int keys_tab[KEYS_TAB_SIZE])
{
	return (keys_tab[KEY_W] || keys_tab[KEY_A] || keys_tab[KEY_S] ||
		keys_tab[KEY_D] || keys_tab[KEY_CTRL] || keys_tab[KEY_SPACEBAR]);
}

void		init_image(t_mlx ptr, t_img *img, int x, int y)
{
	if (!(img->img = mlx_new_image(ptr.mlx, x, y)))
		ft_error("error", 14, perror);
	img->width = x;
	img->height = y;
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->endian);
}

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
