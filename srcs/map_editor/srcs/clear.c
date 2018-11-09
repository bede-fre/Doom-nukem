/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:43:46 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/05 15:33:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** DESTRUCTION DES VARIABLES ALLOUE AVEC LA SDL
*/

void	clear(t_env *env, const char *str, int error)
{
	if (env->renderer)
		SDL_RenderClear(env->renderer);
	if (env->window)
		SDL_DestroyWindow(env->window);
	SDL_Quit();
	ft_error((char*)str, error, ft_puterror);
}
