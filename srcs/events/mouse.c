/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:46:10 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/08 16:01:19 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int						mouse_move(int x, int y, void *param)
{
	t_doom				*env;

	env = param;
	if (env->param.mousepos.x == -6000 && env->param.mousepos.y == -6000)
	{
		env->param.mousepos.x = x;
		env->param.mousepos.y = y;
	}
	else if (env->param.mousepos.x != x || env->param.mousepos.y != y)
		playerrot(env, ft_vecsub(ft_vecdef(x, y, 0), env->param.mousepos));
	env->param.mousepos = ft_vecdef(x, y, 0);
	return (0);
}

int						button_on(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int						button_off(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
