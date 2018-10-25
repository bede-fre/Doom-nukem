/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/25 10:43:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	make_grid(t_env *env)
{
	t_point			p;
	const Uint32	white = set_color(200, 200, 200, 0);
	const Uint32	red = set_color(200, 0, 0, 0);
	t_point			new_gap;
	Uint32			*pixel;
	SDL_PixelFormat	*format;
	SDL_Texture		*texture;
	void			*tmp;
	int				pitch;

	texture = SDL_CreateTexture(env->renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT);
	format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	SDL_LockTexture(texture, NULL, &tmp, &pitch);
	new_gap.x = env->grid.center.x + env->grid.gap.x;
	new_gap.y = env->grid.center.y + env->grid.gap.y;
	pixel = tmp;
	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
		{
			if (abs(p.x - new_gap.x) % env->grid.scale == 0 ||
				abs(p.y - new_gap.y) % env->grid.scale == 0)
				pixel[p.y * WIN_WIDTH + p.x] = white;
			if (p.x == new_gap.x || p.y == new_gap.y)
				pixel[p.y * WIN_WIDTH + p.x] = red;
		}
	}
	SDL_FreeFormat(format);
	SDL_UnlockTexture(texture);
	SDL_RenderCopy(env->renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
}
