/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:35:11 by toliver           #+#    #+#             */
/*   Updated: 2018/10/09 16:04:01 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	playerrot(t_doom *env, t_vec diff)
{
	diff = ft_vecscale(diff, env->param.sensitivity);
	env->player.rot = ft_vecrot(env->player.rot, /*-diff.y*/0.0, 0.0, diff.x);
	env->angle = ft_vec_angle(ft_vecdef(0.0, -1.0, 0.0), env->player.rot);
	env->angle = (env->player.rot.x <= 0.0) ? -env->angle : env->angle;
	env->player.rotangle =
		ft_vecadd(ft_vecdef(diff.z, diff.y, diff.x), env->player.rotangle);
	while (env->player.rotangle.x >= 360.0)
		env->player.rotangle.x -= 360.0;
	while (env->player.rotangle.y >= 360.0)
		env->player.rotangle.y -= 360.0;
	while (env->player.rotangle.z >= 360.0)
		env->player.rotangle.z -= 360.0;
	while (env->player.rotangle.x < 0.0)
		env->player.rotangle.x += 360.0;
	while (env->player.rotangle.y <= 0.0)
		env->player.rotangle.y += 360.0;
	while (env->player.rotangle.z <= 0.0)
		env->player.rotangle.z += 360.0;
	return (1);
}

int	playermove(t_doom *env)
{
	t_vec	dir;
	t_vec	mov;

	dir = ft_vecdef(0.0, 0.0, 0.0);
	mov = ft_vecdef(env->player.rot.x, env->player.rot.y, 0.0);
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
