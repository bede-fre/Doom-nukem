/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:27:21 by cmace             #+#    #+#             */
/*   Updated: 2018/12/06 17:54:23 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

SDL_Texture *what_image(t_textures text, char object)
{
	if (object == T_DOOR)
		return (text.door);
	else if (object == BARREL)
		return (text.t_barrel);
	else if (object == JETPACK)
		return (text.t_jetpack);
	else if (object == PILLAR)
		return (text.t_pillar);
	else if (object == TP_S)
		return (text.t_tp_start);
	else if (object == T_A)
		return (text.t_a);
	else if (object == T_B)
		return (text.t_b);
	else if (object == T_C)
		return (text.t_c);
	else if (object == T_D)
		return (text.t_d);
	else if (object == T_AS)
		return (text.t_a);
	else if (object == T_BS)
		return (text.t_b);
	else if (object == T_CS)
		return (text.t_c);
	else if (object == T_DS)
		return (text.t_d);
	else if (object == UPSTAMI)
		return (text.t_upstami);
    else
        return (NULL);
}

int		is_color(char c)
{
	if (c == TP_E || c == END || c == START)
		return (1);
	return (0);
}