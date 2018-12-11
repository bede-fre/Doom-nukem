/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:27:21 by cmace             #+#    #+#             */
/*   Updated: 2018/12/10 17:49:50 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static SDL_Texture	*what_image2(t_textures text, char object)
{
	if (object == T_CS)
		return (text.t_c);
	else if (object == T_DS)
		return (text.t_d);
	else if (object == UPSTAMI)
		return (text.t_upstami);
	else if (object == MOB)
		return (text.t_mob);
	else
		return (NULL);
}

SDL_Texture			*what_image(t_textures text, char object)
{
	if (object == T_DOOR)
		return (text.door);
	else if (object == BARREL)
		return (text.t_barrel);
	else if (object == JETPACK)
		return (text.t_jetpack);
	else if (object == GIRL)
		return (text.t_girl);
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
	else
		return (what_image2(text, object));
}

static SDL_Surface	*what_surface2(t_surfaces surf, char object)
{
	if (object == T_CS)
		return (surf.s_sc);
	else if (object == T_DS)
		return (surf.s_sd);
	else if (object == UPSTAMI)
		return (surf.s_upstami);
	else if (object == MOB)
		return (surf.s_mob);
	else
		return (NULL);
}

SDL_Surface			*what_surface(t_surfaces surf, char object)
{
	if (object == T_DOOR)
		return (surf.s_door);
	else if (object == BARREL)
		return (surf.s_barrel);
	else if (object == JETPACK)
		return (surf.s_jetpack);
	else if (object == GIRL)
		return (surf.s_girl);
	else if (object == TP_S)
		return (surf.s_tp_start);
	else if (object == T_A)
		return (surf.s_a);
	else if (object == T_B)
		return (surf.s_b);
	else if (object == T_C)
		return (surf.s_c);
	else if (object == T_D)
		return (surf.s_d);
	else if (object == T_AS)
		return (surf.s_sa);
	else if (object == T_BS)
		return (surf.s_sb);
	else
		return (what_surface2(surf, object));
}

int					is_color(char c)
{
	if (c == TP_E || c == END || c == START)
		return (1);
	return (0);
}
