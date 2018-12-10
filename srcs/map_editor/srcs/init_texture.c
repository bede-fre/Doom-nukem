/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:28 by cmace             #+#    #+#             */
/*   Updated: 2018/12/10 17:54:56 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	init_surfaces(t_env *env)
{
	env->surf.s_a = IMG_Load(TEXT_A);
	env->surf.s_b = IMG_Load(TEXT_B);
	env->surf.s_c = IMG_Load(TEXT_C);
	env->surf.s_d = IMG_Load(TEXT_D);
	env->surf.s_barrel = IMG_Load(T_BARREL);
	env->surf.s_jetpack = IMG_Load(T_JETPACK);
	env->surf.s_girl = IMG_Load(T_GIRL);
	env->surf.s_upstami = IMG_Load(T_UPSTAMI);
	env->surf.s_eraser = IMG_Load(ERASER);
	env->surf.s_door = IMG_Load(TEXT_DOOR);
	env->surf.s_sound = IMG_Load(TEXT_SOUND);
	env->surf.s_mute = IMG_Load(TEXT_MUTE);
	env->surf.s_tp_start = IMG_Load(T_TP_START);
	env->surf.s_mob = IMG_Load(T_MOB);
}
