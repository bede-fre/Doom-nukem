/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:43:46 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/22 13:35:13 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	destroy_text(t_env *env)
{
	SDL_DestroyTexture(env->text.t_a);
	SDL_DestroyTexture(env->text.t_b);
	SDL_DestroyTexture(env->text.t_c);
	SDL_DestroyTexture(env->text.t_d);
	SDL_DestroyTexture(env->text.eraser);
	SDL_DestroyTexture(env->text.door);
}

/*
** DESTRUCTION DES VARIABLES ALLOUE AVEC LA SDL
*/

void	clear(t_env *env, const char *str, int error)
{
	if (env->renderer)
		SDL_RenderClear(env->renderer);
	if (env->window)
		SDL_DestroyWindow(env->window);
	if (env->font)
		TTF_CloseFont(env->font);
	destroy_text(env);
	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
	if (str)
		ft_error((char*)str, error, ft_puterror);
	else
		exit(EXIT_SUCCESS);
}
