/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:38:43 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/20 17:02:32 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

typedef struct	s_img
{
	void		*ptr;
	char		*data;

	int			width;
	int			height;

}				t_img;

#define BYTES_PER_PIXEL 4

void			merge_images(t_img *dest, t_img *src, int x, int y)
{
	char		*dest_data;
	int			i;

	i = 0;
	dest_data = dest->data + (y * dest->width + x) * BYTES_PER_PIXEL;
	while (i < src->height)
	{
		memcpy(dest_data, src_data, (src->width > dest->width - x ?
				dest->width - x : src->width) * BYTES_PER_PIXEL);
		if (++i + y >= dest->height)
			break;
		dest_data += (dest->width + x) * BYTES_PER_PIXEL;
		src_data += src->width * BYTES_PER_PIXEL;
	}
}
