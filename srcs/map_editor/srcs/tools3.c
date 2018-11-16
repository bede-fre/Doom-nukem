/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:58:42 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/16 16:44:19 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

char	chose_object(t_button buttons[10], int x, int y, int colision)
{
	if (win_to_map(x) >= 36 && win_to_map(x) <= 40 &&
		win_to_map(y) >= 2 && win_to_map(y) <= 6)
		return ((colision) ? T_A : T_AS);
	if (win_to_map(x) >= 42 && win_to_map(x) <= 46 &&
		win_to_map(y) >= 2 && win_to_map(y) <= 6)
		return ((colision) ? T_B : T_BS);
	if (win_to_map(x) >= 36 && win_to_map(x) <= 40 &&
		win_to_map(y) >= 8 && win_to_map(y) <= 12)
		return ((colision) ? T_C : T_CS);
	if (win_to_map(x) >= 42 && win_to_map(x) <= 46 &&
		win_to_map(y) >= 8 && win_to_map(y) <= 12)
		return ((colision) ? T_D : T_DS);
	if (win_to_map(x) == win_to_map(buttons[B_ERASER].pos.x) &&
		win_to_map(y) == win_to_map(buttons[B_ERASER].pos.y))
		return (FLOOR);
	if (win_to_map(x) == win_to_map(buttons[TP_START].pos.x) &&
		win_to_map(y) == win_to_map(buttons[TP_START].pos.y))
		return (TP_S);
	if (win_to_map(x) == win_to_map(buttons[TP_END].pos.x) &&
		win_to_map(y) == win_to_map(buttons[TP_END].pos.y))
		return (TP_E);
	if (win_to_map(x) == win_to_map(buttons[B_START].pos.x) &&
		win_to_map(y) == win_to_map(buttons[B_START].pos.y))
		return (START);
	return (-1);
}
