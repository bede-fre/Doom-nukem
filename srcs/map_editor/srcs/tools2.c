/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:51:33 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/26 14:00:22 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

SDL_Rect	create_rect(int x, int y, int w, int h)
{
	SDL_Rect rect;

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	return (rect);
}

SDL_Rect	rect_to_map(SDL_Rect rect)
{
	SDL_Rect rect2;

	rect2 = create_rect(win_to_map(rect.x), win_to_map(rect.y), rect.w, rect.h);
	return (rect2);
}

SDL_Rect	rect_to_win(SDL_Rect rect)
{
	SDL_Rect rect2;

	rect2 = create_rect(map_to_win(rect.x), map_to_win(rect.y), rect.w, rect.h);
	return (rect2);
}

int			get_object(char x)
{
	const int	object[] = {WOOD, WOOD, METAL, METAL, STONE, STONE, ICE, ICE,
		TP_START, TP_END, B_START, B_ERASER, B_DOOR, B_END};
	const char	wall[] = {T_A, T_AS, T_B, T_BS, T_C, T_CS, T_D, T_DS, TP_S,
		TP_E, START, FLOOR, T_DOOR, END};
	int			i;

	i = -1;
	while (++i < 14)
		if (x == wall[i])
			return (object[i]);
	return (-1);
}

int			get_colision(int x)
{
	const int	colision[] = {COLISION, NO_COLISION};
	const char	wall[] = {TRUE, FALSE};
	int			i;

	i = -1;
	while (++i < 2)
		if (x == wall[i])
			return (colision[i]);
	return (-1);
}
