/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:58:50 by cmace             #+#    #+#             */
/*   Updated: 2018/11/21 13:51:27 by lguiller         ###   ########.fr       */
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

static void		set_text2(SDL_Surface *surface, t_env *env, const int dim)
{
	t_point	p;

	p = ft_pointdef(map_to_win(36), map_to_win(22));
	set_string(env, "Others:", p, surface);
	p = ft_pointdef(env->buttons[B_START].pos.x + dim,
		env->buttons[B_START].pos.y);
	set_string(env, "Spawn", p, surface);
	p = ft_pointdef(env->buttons[B_DOOR].pos.x + dim,
		env->buttons[B_DOOR].pos.y);
	set_string(env, "Door", p, surface);
	p = ft_pointdef(env->buttons[B_ERASER].pos.x + dim,
		env->buttons[B_ERASER].pos.y);
	set_string(env, "Eraser", p, surface);
}

void			set_text(SDL_Surface *surface, t_env *env)
{
	t_point		p;
	const int	dim = SCALE + (int)((double)SCALE / 4.0);

	p = ft_pointdef(map_to_win(36), map_to_win(30));
	set_string(env, "Press ENTER to generate map", p, surface);
	p = ft_pointdef(map_to_win(36), map_to_win(0));
	set_string(env, "Texture:", p, surface);
	p = ft_pointdef(map_to_win(36), map_to_win(14));
	set_string(env, "Collision:", p, surface);
	p = ft_pointdef(env->buttons[COLISION].pos.x + dim,
		env->buttons[COLISION].pos.y);
	set_string(env, "Yes", p, surface);
	p = ft_pointdef(env->buttons[NO_COLISION].pos.x + dim,
		env->buttons[NO_COLISION].pos.y);
	set_string(env, "No", p, surface);
	p = ft_pointdef(map_to_win(36), map_to_win(18));
	set_string(env, "Teleporter:", p, surface);
	p = ft_pointdef(env->buttons[TP_START].pos.x + dim,
		env->buttons[TP_START].pos.y);
	set_string(env, "Start", p, surface);
	p = ft_pointdef(env->buttons[TP_END].pos.x + dim,
		env->buttons[TP_END].pos.y);
	set_string(env, "Exit", p, surface);
	set_text2(surface, env, dim);
}
