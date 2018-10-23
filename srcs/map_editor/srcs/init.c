/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/23 15:46:35 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	init(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error((char*)SDL_GetError(), 1, ft_puterror);
	if (!(env->win = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_RESIZABLE)))
		ft_error((char*)SDL_GetError(), 2, ft_puterror);
}
