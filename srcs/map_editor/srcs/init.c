/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/23 16:25:29 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	init(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error((char*)SDL_GetError(), 1, ft_puterror);
	if (!(env->window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_RESIZABLE)))
		ft_error((char*)SDL_GetError(), 2, ft_puterror);
	env->img->renderer = SDL_CreateRenderer(env->window, -1, 0);
	env->img->texture = SDL_CreateTexture(env->img->renderer,
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 200, 200);
}
