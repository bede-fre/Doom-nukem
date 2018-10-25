/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:20:07 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/25 09:22:46 by lguiller         ###   ########.fr       */
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
		env->grid.scale += 1;
	if (env->keys[K_ZOOMOUT])
		env->grid.scale -= (env->grid.scale > 1) ? 1 : 0;
	clear_window(env->renderer);
	make_grid(env);
	SDL_RenderPresent(env->renderer);
}
