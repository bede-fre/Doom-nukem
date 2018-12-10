/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:12:18 by cmace             #+#    #+#             */
/*   Updated: 2018/12/10 17:58:44 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static Uint32	find_src_pixel_col(SDL_Surface *surface, int x, int y)
{
	int		number_octet_by_pixel;
	Uint32	col;

	number_octet_by_pixel = surface->format->BytesPerPixel;
	if (!*(Uint8*)(surface->pixels + y * surface->pitch + x
		* number_octet_by_pixel + 3))
		col = LIGHT_GREY;
	else
		col = ((*(Uint8*)(surface->pixels + y * surface->pitch + x
			* number_octet_by_pixel + 2) << 24) | (*(Uint8*)(surface->pixels + y
			* surface->pitch + x * number_octet_by_pixel + 1) << 16)
			| (*(Uint8*)(surface->pixels + y * surface->pitch + x
			* number_octet_by_pixel) << 8) | (Uint8)0xFF);
	return (col);
}

void			scale_surface(SDL_Surface *dst, SDL_Surface *src, SDL_Rect *r)
{
	SDL_Rect	rect;
	t_point		p;

	(void)r;
	if (r == NULL)
		rect = create_rect(0, 0, dst->w, dst->h);
	else
		rect = create_rect(r->x, r->y, r->w, r->h);
	p.y = -1;
	while (++p.y < rect.h)
	{
		p.x = -1;
		while (++p.x < rect.w)
			fill_px(dst, p.x + rect.x, p.y + rect.y, find_src_pixel_col(src,
				(int)((double)p.x * (double)src->w / (double)rect.w),
				(int)((double)p.y * (double)src->h / (double)rect.h)));
	}
}
