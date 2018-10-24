/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/24 11:24:54 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE LA SDL, DE LA FENETRE ET DU RENDERER
*/

void	init(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error((char*)SDL_GetError(), 1, ft_puterror);
	if (!(env->window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_RESIZABLE)))
		ft_error((char*)SDL_GetError(), 2, ft_puterror);
	if (!(env->renderer = SDL_CreateRenderer(env->window, -1, 0)))
		ft_error((char*)SDL_GetError(), 3, ft_puterror);
	env->grid.scale = 25;
	env->grid.gap.x = 1920 / 2;
	env->grid.gap.y = 1080 / 2;
}
