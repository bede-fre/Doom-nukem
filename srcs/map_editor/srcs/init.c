/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/24 14:51:34 by lguiller         ###   ########.fr       */
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
	if (!(env->window = SDL_CreateWindow("GAME EDITOR", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_RESIZABLE)))
		ft_error((char*)SDL_GetError(), 2, ft_puterror);
	if (!(env->renderer = SDL_CreateRenderer(env->window, -1, 0)))
		ft_error((char*)SDL_GetError(), 3, ft_puterror);
	env->grid.scale = 50;
	env->grid.gap_scale = (int)((float)env->grid.scale / 2.5f);
	env->grid.center.x = WIN_WIDTH / 2;
	env->grid.center.y = WIN_HEIGHT / 2;
	env->grid.gap.x = 0;
	env->grid.gap.y = 0;
}
