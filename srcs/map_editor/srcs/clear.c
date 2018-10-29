/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:43:46 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 12:54:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	clear(t_env *env, t_draw *draw, const char *str, int error)
{
	if (draw)
	{
		if (draw->surface)
			SDL_FreeSurface(draw->surface);
		if (draw->texture)
			SDL_DestroyTexture(draw->texture);
	}
	if (env->renderer)
		SDL_RenderClear(env->renderer);
	if (env->window)
		SDL_DestroyWindow(env->window);
	SDL_Quit();
	ft_error((char*)str, error, ft_puterror);
}
