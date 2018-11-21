/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:07:18 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/21 11:43:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static t_button	create_button(SDL_Rect rect, int button_col, int border_col,
		SDL_Texture *texture)
{
	t_button button;

	button.pos.x = rect.x;
	button.pos.y = rect.y;
	button.size.x = rect.w;
	button.size.y = rect.h;
	button.rect.x = rect.x;
	button.rect.y = rect.y;
	button.rect.w = rect.w;
	button.rect.h = rect.h;
	button.button_col = button_col;
	button.border_col = border_col;
	button.texture = texture;
	return (button);
}

void			init_button(t_env *env)
{
	SDL_Rect	rect;
	const int	dim1 = SCALE * 5;
	const int	dim2 = SCALE;

	rect = create_rect(map_to_win(38), map_to_win(20), dim2, dim2);
	env->buttons[TP_START] = create_button(rect, TP_S_COL, BLACK, NULL);
	rect = create_rect(map_to_win(44), map_to_win(20), dim2, dim2);
	env->buttons[TP_END] = create_button(rect, TP_E_COL, BLACK, NULL);
	rect = create_rect(map_to_win(38), map_to_win(24), dim2, dim2);
	env->buttons[B_START] = create_button(rect, START_COL, BLACK, NULL);
	rect = create_rect(map_to_win(38), map_to_win(16), dim2, dim2);
	env->buttons[COLISION] = create_button(rect, BLACK, BLACK, NULL);
	rect = create_rect(map_to_win(44), map_to_win(16), dim2, dim2);
	env->buttons[NO_COLISION] = create_button(rect, BLACK, BLACK, NULL);
	rect = create_rect(map_to_win(38), map_to_win(26), dim2, dim2);
	env->buttons[B_ERASER] = create_button(rect, BLACK, BLACK,
		env->text.eraser);
	rect = create_rect(map_to_win(36) + 2, map_to_win(2) + 2, dim1, dim1);
	env->buttons[WOOD] = create_button(rect, BLACK, BLACK, env->text.t_a);
	rect = create_rect(map_to_win(42) + 2, map_to_win(2) + 2, dim1, dim1);
	env->buttons[METAL] = create_button(rect, BLACK, BLACK, env->text.t_b);
	rect = create_rect(map_to_win(36) + 2, map_to_win(8) + 2, dim1, dim1);
	env->buttons[STONE] = create_button(rect, BLACK, BLACK, env->text.t_c);
	rect = create_rect(map_to_win(42) + 2, map_to_win(8) + 2, dim1, dim1);
	env->buttons[ICE] = create_button(rect, BLACK, BLACK, env->text.t_d);
}
