/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/23 17:09:14 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	ft_loop(void)
{
	int			loop;
	t_env		env;
	SDL_Event	event;
	SDL_Color orange = {255, 127, 40, 125};

	loop = 1;
	init(&env);
	while (loop)
	{
		if (SDL_PollEvent(&event) == 1)
			events(event, &loop);
		SDL_DestroyRenderer(env.img->renderer);
		env.img->renderer = SDL_CreateRenderer(env.window, -1, 0);
		SDL_SetRenderDrawColor(env.img->renderer, orange.r, orange.g, orange.b, orange.a);
		SDL_RenderClear(env.img->renderer);
		SDL_RenderPresent(env.img->renderer);
	}
	SDL_DestroyWindow(env.window);
	SDL_Quit();
}

int			main(void)
{
	ft_loop();
	return (EXIT_SUCCESS);
}
