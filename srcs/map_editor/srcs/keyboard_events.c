/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:20:07 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/25 14:35:44 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** GESTION DES ACTIONS A EFFECTUER LORS D'UN EVENEMENT CLAVIER
*/

void	keyboard_events(t_env *env)
{
	if (env->keys[K_UP])
		env->grid.gap.y += env->grid.gap_scale;
	if (env->keys[K_DOWN])
		env->grid.gap.y -= env->grid.gap_scale;
	if (env->keys[K_LEFT])
		env->grid.gap.x += env->grid.gap_scale;
	if (env->keys[K_RIGHT])
		env->grid.gap.x -= env->grid.gap_scale;
	if (env->keys[K_ZOOMIN])
		env->grid.scale += (env->grid.scale < 50) ? 1 : 0;
	if (env->keys[K_ZOOMOUT])
		env->grid.scale -= (env->grid.scale > 1) ? 1 : 0;
	if ((*env->keys || *(env->keys + 1) || *(env->keys + 2) || *(env->keys + 3) ||
		*(env->keys + 4) || *(env->keys + 5)))
	{
		if ((env->grid.scale < 50 && env->grid.scale > 1) || (!env->keys[K_ZOOMIN] && !env->keys[K_ZOOMOUT]))
		{
			make_grid(env);
			SDL_RenderPresent(env->renderer);
		}
	}
}
