/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:35:11 by toliver           #+#    #+#             */
/*   Updated: 2018/09/24 17:24:37 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			playerrot(t_doom *env, t_vec diff)
{
	printf("PLAYER ROTATION:\n");
	diff = ft_vecscale(diff, env->param.sensitivity);
	ft_printvector(diff);
	ft_printvector(env->player.rot);
	env->player.rot = ft_vecrot(env->player.rot, diff.y, 0, diff.x);
	ft_printvector(env->player.rot);
	return (1);
}

int			playermove(t_doom *env)
{
	t_vec	movedirection;
	t_vec	flattenedmovement;

//	printf("PLAYER MOVEMENT:\n");
	movedirection = ft_vecdef(0, 0, 0);
	flattenedmovement = ft_vecdef(env->player.rot.x, env->player.rot.y, 0);
	flattenedmovement = ft_vecnormalize(flattenedmovement);
//	ft_printvector(flattenedmovement);
//	ft_printvector(env->player.pos);
	if (is_key_pressed(env, K_FORWARD))
	{
//		printf("FORWARD\n");
		movedirection = ft_vecadd(movedirection, flattenedmovement);
	}
	if (is_key_pressed(env, K_BACKWARD))
	{
//		printf("BACKWARD\n");
		movedirection = ft_vecsub(movedirection, flattenedmovement);
	}
	if (is_key_pressed(env, K_LEFT))
	{
//		printf("LEFT\n");
		movedirection = ft_vecadd(movedirection, ft_vecrotz(flattenedmovement, -90));
	}
	if (is_key_pressed(env, K_RIGHT))
	{
//		printf("RIGHT\n");
		movedirection = ft_vecadd(movedirection, ft_vecrotz(flattenedmovement, 90));
	}
	if (ft_vecnorm(movedirection) != 0)
	{
		if (ft_vecnorm(movedirection) > 1.00)
			movedirection = ft_vecnormalize(movedirection);
	}
//	ft_printvector(movedirection);
//	ft_printvector(env->player.pos);
	env->player.pos = ft_vecadd(env->player.pos, ft_vecscale(movedirection, env->player.speed));
//	ft_printvector(movedirection);
//	ft_printvector(env->player.pos);
	return (1);
}
