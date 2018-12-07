/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:20:28 by cmace             #+#    #+#             */
/*   Updated: 2018/12/06 19:54:49 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	init_next_textures(t_env *env)
{
	SDL_Surface *surface;

	surface = IMG_Load(TEXT_DOOR);
	env->text.door = create_texture(surface, env);
	surface = IMG_Load(TEXT_SOUND);
	env->text.sound = create_texture(surface, env);
	surface = IMG_Load(TEXT_MUTE);
	env->text.mute = create_texture(surface, env);
	surface = IMG_Load(T_TP_START);
	env->text.t_tp_start = create_texture(surface, env);
	surface = IMG_Load(T_MOB);
	env->text.t_mob = create_texture(surface, env);
}

void		init_textures(t_env *env)
{
	SDL_Surface *surface;

	surface = IMG_Load(TEXT_A);
	env->text.t_a = create_texture(surface, env);
	surface = IMG_Load(TEXT_B);
	env->text.t_b = create_texture(surface, env);
	surface = IMG_Load(TEXT_C);
	env->text.t_c = create_texture(surface, env);
	surface = IMG_Load(TEXT_D);
	env->text.t_d = create_texture(surface, env);
	surface = IMG_Load(T_BARREL);
	env->text.t_barrel = create_texture(surface, env);
	surface = IMG_Load(T_JETPACK);
	env->text.t_jetpack = create_texture(surface, env);
	surface = IMG_Load(T_PILLAR);
	env->text.t_pillar = create_texture(surface, env);
	surface = IMG_Load(T_UPSTAMI);
	env->text.t_upstami = create_texture(surface, env);
	surface = IMG_Load(ERASER);
	env->text.eraser = create_texture(surface, env);
	init_next_textures(env);
}
