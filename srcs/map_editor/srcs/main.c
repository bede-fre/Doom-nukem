/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/24 11:01:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE ENV ET LANCEMENT DE LA BOUCLE DES EVENTS
*/

static void	ft_loop(void)
{
	int			loop;
	t_env		env;
	SDL_Event	event;
	SDL_Color	color = {255, 255, 255, 0};
	int			x;
	int			y;

	loop = 1;
	init(&env);
	y = -1;
	while (++y < 1080 && (x = -1))
		while (++x < 1920)
			if (x % SCALE == 0 || y % SCALE == 0)
				set_pixel(env.renderer, x, y, color);
	SDL_RenderPresent(env.renderer);
	while (loop)
	{
		if (SDL_PollEvent(&event) == 1)
			events(event, &loop, &env);
	}
	SDL_DestroyWindow(env.window);
	SDL_Quit();
}

int			main(void)
{
	ft_loop();
	return (EXIT_SUCCESS);
}
