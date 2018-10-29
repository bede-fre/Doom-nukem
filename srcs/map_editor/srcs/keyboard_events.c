/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:20:07 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 13:07:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** DEPLACEMENTS DE LA CAMERA
*/

void	movements(t_env *env)
{
	if (env->keys[K_UP])
		env->grid.gap.y += env->grid.scale * 10;
	if (env->keys[K_DOWN])
		env->grid.gap.y -= env->grid.scale * 10;
	if (env->keys[K_LEFT])
		env->grid.gap.x += env->grid.scale * 10;
	if (env->keys[K_RIGHT])
		env->grid.gap.x -= env->grid.scale * 10;
}

/*
** GESTION DES ACTIONS A EFFECTUER LORS D'UN EVENEMENT CLAVIER
*/

void	keyboard_events(t_env *env)
{
	movements(env);
	if (env->keys[K_RESET])
	{
		env->grid.gap.x = 0;
		env->grid.gap.y = 0;
	}
	if (env->keys[K_ZOOMIN])
		env->grid.scale += (env->grid.scale < 20) ? 1 : 0;
	if (env->keys[K_ZOOMOUT])
		env->grid.scale -= (env->grid.scale > 1) ? 1 : 0;
	if ((*env->keys || *(env->keys + 1) || *(env->keys + 2) || *(env->keys + 3)
		|| *(env->keys + 4) || *(env->keys + 5) || *(env->keys + 6)))
	{
		if ((env->grid.scale < 20 && env->grid.scale > 1)
			|| (!env->keys[K_ZOOMIN] && !env->keys[K_ZOOMOUT]))
			start_draw(env);
	}
}
