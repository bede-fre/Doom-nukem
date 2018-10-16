/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:35:11 by toliver           #+#    #+#             */
/*   Updated: 2018/10/16 17:03:58 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	playerrot(t_doom *env, t_vec diff)
{
	diff = ft_vecscale(diff, env->param.sensitivity);
	env->player.body = ft_vecrot(env->player.body, 0.0, 0.0, diff.x);
	
	env->player.head = ft_vecrot(env->player.body, -diff.y, 0.0, 0.0);
	env->angle = ft_vec_angle(ft_vecdef(0.0, -1.0, 0.0), env->player.body);
	env->angle = (env->player.body.x <= 0.0) ? -env->angle : env->angle;
	return (1);
}

int	playermove(t_doom *env)
{
	t_vec	dir;
	t_vec	mov;

	dir = ft_vecdef(0.0, 0.0, 0.0);
	mov = ft_vecdef(env->player.body.x, env->player.body.y, 0.0);
	mov = ft_vecnormalize(mov);
	if (is_key_pressed(env, K_FORWARD))
		dir = ft_vecadd(dir, mov);
	if (is_key_pressed(env, K_BACKWARD))
		dir = ft_vecsub(dir, mov);
	if (is_key_pressed(env, K_LEFT))
		dir = ft_vecadd(dir, ft_vecrotz(mov, -90.0));
	if (is_key_pressed(env, K_RIGHT))
		dir = ft_vecadd(dir, ft_vecrotz(mov, 90.0));
	if (ft_vecnorm(dir) > 1.0)
		dir = ft_vecnormalize(dir);
	env->player.pos = ft_vecadd(env->player.pos,
		ft_vecscale(dir, env->player.speed));
	return (1);
}
