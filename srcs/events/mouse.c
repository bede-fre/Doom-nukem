/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:46:10 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/09 16:00:11 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	mouse_move(int x, int y, void *param)
{
	t_doom	*env;

	env = (t_doom*)param;
	if (env->param.mousepos.x == -6000.0 && env->param.mousepos.y == -6000.0)
	{
		env->param.mousepos.x = (float)x;
		env->param.mousepos.y = (float)y;
	}
	else if (env->param.mousepos.x != (float)x
	|| env->param.mousepos.y != (float)y)
		playerrot(env, ft_vecsub(ft_vecdef((float)x, (float)y, 0.0),
			env->param.mousepos));
	env->param.mousepos = ft_vecdef((float)x, (float)y, 0.0);
	return (0);
}

int	button_on(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}

int	button_off(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
