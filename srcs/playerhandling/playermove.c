/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:35:11 by toliver           #+#    #+#             */
/*   Updated: 2018/10/19 09:41:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int	playerrot(t_doom *env, t_vec diff)
{
	t_vec	vec_tmp;
	float	tmp;

	diff = ft_vecscale(diff, env->param.sensitivity);
	env->player.body = ft_vecrotz(env->player.body, diff.x);
	vec_tmp = ft_vecrotx(env->player.head, diff.y);
	env->angle = ft_vec_angle(ft_vecdef(0.0f, -1.0f, 0.0f), env->player.body);
	env->angle = (env->player.body.x <= 0.0f) ? -env->angle : env->angle;
	if (vec_tmp.z >= -0.8f && vec_tmp.z <= 0.8f)
	{
		tmp = vec_tmp.z + 0.5f;
		env->wall_center = WIN_HEIGHT * tmp;
		env->player.head = vec_tmp;
	}
	return (1);
}

int	playermove(t_doom *env)
{
	t_vec	dir;
	t_vec	mov;

	dir = ft_vecdef(0.0f, 0.0f, 0.0f);
	mov = ft_vecdef(env->player.body.x, env->player.body.y, 0.0f);
	mov = ft_vecnormalize(mov);
	if (is_key_pressed(env, K_FORWARD))
		dir = ft_vecadd(dir, mov);
	if (is_key_pressed(env, K_BACKWARD))
		dir = ft_vecsub(dir, mov);
	if (is_key_pressed(env, K_LEFT))
		dir = ft_vecadd(dir, ft_vecrotz(mov, -90.0f));
	if (is_key_pressed(env, K_RIGHT))
		dir = ft_vecadd(dir, ft_vecrotz(mov, 90.0f));
	if (ft_vecnorm(dir) > 1.0f)
		dir = ft_vecnormalize(dir);
	env->player.pos = ft_vecadd(env->player.pos, ft_vecscale(dir,
		env->player.speed));
	return (1);
}
