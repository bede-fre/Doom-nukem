/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:58:50 by cmace             #+#    #+#             */
/*   Updated: 2018/11/16 16:40:04 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void		set_string(t_env *env, const char *s, t_point p,
	SDL_Surface *surface)
{
	const SDL_Color		noir = {0, 0, 0, 255};
	SDL_Surface			*text;
	SDL_Rect			position;

	text = TTF_RenderText_Blended(env->font, (char*)s, noir);
	position.x = p.x;
	position.y = p.y;
	SDL_BlitSurface(text, NULL, surface, &position);
	SDL_FreeSurface(text);
}

void			set_text(SDL_Surface *surface, t_env *env)
{
	set_string(env, "Texture:", ft_pointdef(map_to_win(36), map_to_win(0)),
		surface);
	set_string(env, "Collision:", ft_pointdef(map_to_win(36), map_to_win(14)),
		surface);
	set_string(env, "yes", ft_pointdef(env->buttons[COLISION].pos.x +
		SCALE + (int)((double)SCALE / 4.0), env->buttons[COLISION].pos.y -
		(int)((double)SCALE / 4.0)), surface);
	set_string(env, "no", ft_pointdef(env->buttons[NO_COLISION].pos.x +
		SCALE + (int)((double)SCALE / 4.0), env->buttons[NO_COLISION].pos.y -
		(int)((double)SCALE / 4.0)), surface);
	set_string(env, "Teleporter:", ft_pointdef(map_to_win(36), map_to_win(18)),
		surface);
	set_string(env, "start", ft_pointdef(env->buttons[TP_START].pos.x +
		SCALE + (int)((double)SCALE / 4.0), env->buttons[TP_START].pos.y -
		(int)((double)SCALE / 4.0)), surface);
	set_string(env, "exit", ft_pointdef(env->buttons[TP_END].pos.x + SCALE +
		(int)((double)SCALE / 4.0), env->buttons[TP_END].pos.y -
		(int)((double)SCALE / 4.0)), surface);
	set_string(env, "Others:", ft_pointdef(map_to_win(36), map_to_win(22)),
		surface);
	set_string(env, "spawn", ft_pointdef(env->buttons[B_START].pos.x +
		SCALE + (int)((double)SCALE / 4.0), env->buttons[B_START].pos.y -
		(int)((double)SCALE / 4.0)), surface);
	set_string(env, "eraser", ft_pointdef(env->buttons[B_ERASER].pos.x +
		SCALE + (int)((double)SCALE / 4.0), env->buttons[B_ERASER].pos.y -
		(int)((double)SCALE / 4.0)), surface);
}
