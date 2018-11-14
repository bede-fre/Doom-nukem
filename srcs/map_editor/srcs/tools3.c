/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:58:42 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/14 15:21:24 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

char	chose_object(int x, int y, int colision)
{
	if (win_to_map(x) >= 36 && win_to_map(x) <= 40 &&
		win_to_map(y) >= 0 && win_to_map(y) <= 4)
		return ((colision) ? T_A : T_AS);
	if (win_to_map(x) >= 42 && win_to_map(x) <= 46 &&
		win_to_map(y) >= 0 && win_to_map(y) <= 4)
		return ((colision) ? T_B : T_BS);
	if (win_to_map(x) >= 36 && win_to_map(x) <= 40 &&
		win_to_map(y) >= 6 && win_to_map(y) <= 10)
		return ((colision) ? T_C : T_CS);
	if (win_to_map(x) >= 42 && win_to_map(x) <= 46 &&
		win_to_map(y) >= 6 && win_to_map(y) <= 10)
		return ((colision) ? T_D : T_DS);
	if (win_to_map(x) == 41 && win_to_map(y) == 20)
		return (FLOOR);
	if (win_to_map(x) == 38 && win_to_map(y) == 18)
		return (TP_S);
	if (win_to_map(x) == 41 && win_to_map(y) == 18)
		return (TP_E);
	if (win_to_map(x) == 44 && win_to_map(y) == 18)
		return (START);
	return (-1);
}
