/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:30:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/03 13:32:18 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static Uint32	col_wall2(char object)
{
	if (object == START)
		return (START_COL);
	else if (object == T_DOOR)
		return (T_DOOR_COL);
	else if (object == END)
		return (END_COL);
	else if (object == T_BARREL)
		return (GREEN);
	else
		return (0);
}

static Uint32	col_wall(char object)
{
	if (object == T_A)
		return (T_A_COL);
	else if (object == T_B)
		return (T_B_COL);
	else if (object == T_C)
		return (T_C_COL);
	else if (object == T_D)
		return (T_D_COL);
	else if (object == T_AS)
		return (T_AS_COL);
	else if (object == T_BS)
		return (T_BS_COL);
	else if (object == T_CS)
		return (T_CS_COL);
	else if (object == T_DS)
		return (T_DS_COL);
	else if (object == TP_S)
		return (TP_S_COL);
	else if (object == TP_E)
		return (TP_E_COL);
	else
		return (col_wall2(object));
}

void			print_map(SDL_Surface *surface, char map[MAP_HEIGHT][MAP_WIDTH])
{
	t_point p;

	p.y = -1;
	while (++p.y < MAP_HEIGHT)
	{
		p.x = -1;
		while (++p.x < MAP_WIDTH)
			if (map[p.y][p.x] != ' ')
				fill_rect(surface, point_to_win(p), col_wall(map[p.y][p.x]));
	}
}
