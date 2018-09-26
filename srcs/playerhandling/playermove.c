/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:35:11 by toliver           #+#    #+#             */
/*   Updated: 2018/09/26 10:34:12 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			playerrot(t_doom *env, t_vec diff)
{
	diff = ft_vecscale(diff, env->param.sensitivity);
	env->player.rot = ft_vecrot(env->player.rot, /*-diff.y*/0.0, 0.0, diff.x);

	env->angle = ft_vec_angle(ft_vecdef(0.0, -1.0, 0.0), env->player.rot);
	env->angle = (env->player.rot.x <= 0.0) ? -env->angle : env->angle;

	return (1);
}

int			playermove(t_doom *env)
{
	t_vec	movedirection;
	t_vec	flattenedmovement;

	movedirection = ft_vecdef(0, 0, 0);
	flattenedmovement = ft_vecdef(env->player.rot.x, env->player.rot.y, 0);
	flattenedmovement = ft_vecnormalize(flattenedmovement);
	if (is_key_pressed(env, K_FORWARD))
		movedirection = ft_vecadd(movedirection, flattenedmovement);
	if (is_key_pressed(env, K_BACKWARD))
		movedirection = ft_vecsub(movedirection, flattenedmovement);
	if (is_key_pressed(env, K_LEFT))
		movedirection = ft_vecadd(movedirection, ft_vecrotz(flattenedmovement, -90));
	if (is_key_pressed(env, K_RIGHT))
		movedirection = ft_vecadd(movedirection, ft_vecrotz(flattenedmovement, 90));
	if (ft_vecnorm(movedirection) != 0)
		if (ft_vecnorm(movedirection) > 1.00)
			movedirection = ft_vecnormalize(movedirection);
	env->player.pos = ft_vecadd(env->player.pos, ft_vecscale(movedirection, env->player.speed));
	return (1);
}
