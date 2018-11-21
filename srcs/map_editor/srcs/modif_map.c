/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:43:48 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/21 11:32:51 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	delete_car(t_env *env)
{
	t_point p;

	p.y = -1;
	while (++p.y < MAP_HEIGHT)
	{
		p.x = -1;
		while (++p.x < MAP_WIDTH)
		{
			if (env->map[p.y][p.x] == env->object)
			{
				env->map[p.y][p.x] = ' ';
				return ;
			}
		}
	}
}

void		modif_map(t_env *env)
{
	t_point	i;

	i = ft_pointdef(win_to_map(env->mouse.x), win_to_map(env->mouse.y));
	if (i.x >= 0 && i.x < MAP_WIDTH && i.y >= 0 && i.y < MAP_HEIGHT &&
		env->map[i.y][i.x] != env->object)
	{
		if (env->object == START || env->object == TP_E)
			delete_car(env);
		if (env->map[i.y][i.x] != START)
		{
			env->map[i.y][i.x] = env->object;
			Mix_PlayMusic(get_sounds(env, env->object), 1);
		}
		else
			Mix_PlayMusic(env->sounds.error, 1);
	}
}
