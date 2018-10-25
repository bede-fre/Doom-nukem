/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:31:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/25 14:45:30 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	init_draw(t_draw *draw, t_env *env)
{
	draw->texture = SDL_CreateTexture(env->renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING, WIN_WIDTH, WIN_HEIGHT);
	draw->format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	SDL_LockTexture(draw->texture, NULL, &draw->tmp, &draw->sizeline);
	draw->pixel = draw->tmp;
}

static void uninit_draw(t_draw *draw, t_env *env)
{
	SDL_FreeFormat(draw->format);
	SDL_UnlockTexture(draw->texture);
	SDL_RenderCopy(env->renderer, draw->texture, NULL, NULL);
	SDL_DestroyTexture(draw->texture);
}

void	make_grid(t_env *env)
{
	t_point			p;
	const Uint32	white = set_color(100, 100, 100, 0);
	const Uint32	red = set_color(200, 0, 0, 0);
	t_point			new_gap;
	t_draw			draw;

	init_draw(&draw, env);
	new_gap.x = env->grid.center.x + env->grid.gap.x;
	new_gap.y = env->grid.center.y + env->grid.gap.y;
	p.y = -1;
	while (++p.y < WIN_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIN_WIDTH)
		{
			if (abs(p.x - new_gap.x) % env->grid.scale == 0 ||
				abs(p.y - new_gap.y) % (env->grid.scale) == 0)
				draw.pixel[p.y * WIN_WIDTH + p.x] = white;
			if (p.x == new_gap.x || p.y == new_gap.y)
				draw.pixel[p.y * WIN_WIDTH + p.x] = red;
		}
	}
	uninit_draw(&draw, env);
}
