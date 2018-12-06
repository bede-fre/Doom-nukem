/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:30:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/06 18:25:16 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static Uint32	col_wall(char object)
{
	if (object == START)
		return (START_COL);
	if (object == TP_E)
		return (TP_E_COL);
	else if (object == END)
		return (END_COL);
	else
		return (0);
}

void			print_map(SDL_Surface *surface,
					char map[MAP_HEIGHT][MAP_WIDTH])
{
	t_point p;

	p.y = -1;
	while (++p.y < MAP_HEIGHT)
	{
		p.x = -1;
		while (++p.x < MAP_WIDTH)
		{
			if (is_color(map[p.y][p.x]))
				fill_rect(surface, point_to_win(p),
					col_wall(map[p.y][p.x]));
		}
	}
}

void			print_maptexture(char map[MAP_HEIGHT][MAP_WIDTH],
					t_env *env)
{
	t_point		p;
	SDL_Rect	rect;

	p.y = -1;
	while (++p.y < MAP_HEIGHT)
	{
		p.x = -1;
		while (++p.x < MAP_WIDTH)
		{
			if (is_image(map[p.y][p.x]))
			{
				rect = create_rect(map_to_win(p.x),
					map_to_win(p.y), SCALE, SCALE);
				if (SDL_RenderCopy(env->renderer,
					what_image(env->text, map[p.y][p.x]), NULL, &rect) < 0)
					ft_error((char*)SDL_GetError(), 25, ft_puterror);
			}
		}
	}
}
