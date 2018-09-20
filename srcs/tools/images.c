/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:38:43 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/20 19:28:10 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			merge_images(t_img *dest, t_img *src, int x, int y)
{
	char		*dest_data;
	char		*src_data;
	int			i;

	i = 0;
	if (x >= dest->width || y >= dest->height)
		return ;
	dest_data = dest->data + ((y >= 0 ? y : 0) * dest->width +
		(x >= 0 ? x : 0)) * BYTES_PER_PIXEL;
	src_data = src->data;
	while (i < src->height)
	{
		if (y >= 0 || i + y >= 0)
		{
			if (x < 0 && x + src->width > 0)
				memcpy(dest_data, src_data - (x * BYTES_PER_PIXEL), 
				(src->width + x > dest->width ?
					dest->width : src->width + x) * BYTES_PER_PIXEL);
			else if (x >= 0)
				memcpy(dest_data, src_data, (src->width > dest->width - x ?
					dest->width - x : src->width) * BYTES_PER_PIXEL);
		}
		if (++i + y >= dest->height)
			break;
		if (i + y > 0)
			dest_data += dest->width * BYTES_PER_PIXEL;
		src_data += src->width * BYTES_PER_PIXEL;
	}
}
