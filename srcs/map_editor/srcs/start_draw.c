/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:06:22 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 13:07:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	start_draw(t_env *env)
{
	SDL_RenderClear(env->renderer);
	make_grid(env);
	SDL_RenderPresent(env->renderer);
}
