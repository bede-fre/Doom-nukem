/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buttons.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 10:22:56 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/16 15:46:13 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	print_border_textures_buttons(t_env *env, SDL_Surface *surface,
		char object)
{
	int x;

	x = get_object(object);
	fill_border(surface, env->buttons[x].pos, env->buttons[x].size.x,
		env->buttons[x].border_col);
}

static void	print_others_buttons(t_env *env, SDL_Surface *surface)
{
	fill_rect(surface, env->buttons[TP_START].pos,
		env->buttons[TP_START].button_col);
	fill_rect(surface, env->buttons[TP_END].pos,
		env->buttons[TP_END].button_col);
	fill_rect(surface, env->buttons[B_START].pos,
		env->buttons[B_START].button_col);
	fill_border(surface, env->buttons[COLISION].pos,
		env->buttons[COLISION].size.x, env->buttons[COLISION].button_col);
	fill_border(surface, env->buttons[NO_COLISION].pos,
		env->buttons[NO_COLISION].size.x, env->buttons[NO_COLISION].button_col);
}

static void	print_border_others_button(t_env *env, SDL_Surface *surface,
		char object, int colision)
{
	int x;

	x = get_object(object);
	fill_border(surface, env->buttons[x].pos, env->buttons[x].size.x,
		env->buttons[x].border_col);
	x = get_colision(colision);
	fill_cross(surface, env->buttons[x].pos, env->buttons[x].button_col);
}

void		print_buttons(t_env *env, SDL_Surface *surface, char object,
	int colision)
{
	print_border_textures_buttons(env, surface, object);
	print_others_buttons(env, surface);
	print_border_others_button(env, surface, object, colision);
}
