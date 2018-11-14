/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:49:10 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/14 15:22:09 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	change_colision(t_env *env, char *object, int *colision)
{
	if (win_to_map(env->mouse.x) == 38 && win_to_map(env->mouse.y) == 14)
	{
		*colision = TRUE;
		if (*object == T_AS || *object == T_BS ||
			*object == T_CS || *object == T_DS)
			*object -= 32;
	}
	else if (win_to_map(env->mouse.x) == 44 && win_to_map(env->mouse.y) == 14)
	{
		*colision = FALSE;
		if (*object == T_A || *object == T_B ||
			*object == T_C || *object == T_D)
			*object += 32;
	}
}

static void	change_object(t_env *env, char *object)
{
	char x;

	x = chose_object(env->mouse.x, env->mouse.y, env->colision);
	if (x != -1)
		*object = x;
}

/*
** GESTION DES ACTIONS A EFFECTUER LORS D'UN EVENEMENT CLAVIER
*/

void		refresh_events(t_env *env)
{
	if (env->keys[B_LEFT])
	{
		change_colision(env, &env->object, &env->colision);
		change_object(env, &env->object);
		modif_map(env);
	}
	if (env->keys[K_RENDER])
	{
		write_file(env->file_name, env->map);
		clear(env, NULL, 0);
	}
	start_draw(env);
}
