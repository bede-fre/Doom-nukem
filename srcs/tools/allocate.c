/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:13:12 by toliver           #+#    #+#             */
/*   Updated: 2018/10/12 14:45:29 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	img_get(t_img *img, int x, int y, t_doom *env)
{
	if (!(img->ptr = mlx_new_image(env->mlx, x, y)))
		ft_error("Failed to initialize new image");
	if (!(img->data = mlx_get_data_addr(img->ptr, &(img->bpp),
			&(img->linesize), &(img->endian))))
		ft_error("Failed to initialize new image");
	img->width = x;
	img->height = y;
}
