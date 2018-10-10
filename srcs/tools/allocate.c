/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:13:12 by toliver           #+#    #+#             */
/*   Updated: 2018/10/10 14:22:06 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_wall	*get_wall(char type, int nextzone, t_vec origin)
{
	t_wall	*ptr;

	ptr = (t_wall*)ft_memalloc(sizeof(t_wall));
	ptr->type = type;
	ptr->nextzone = nextzone;
	ptr->origin = origin;
	return (ptr);
}

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
