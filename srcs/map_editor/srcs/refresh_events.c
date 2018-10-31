/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:49:10 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/31 17:27:23 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** DEPLACEMENTS DE LA CAMERA
*/

static void	movements(t_env *env)
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

void		refresh_events(t_env *env)
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
	if (env->keys[B_LEFT])
	{
		stock_map(env);
		printf("x: %d y: %d \n", env->sector->vertex->p.x, env->sector->vertex->p.y);
	}
	start_draw(env);
}
