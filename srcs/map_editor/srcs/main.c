/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/26 16:19:31 by lguiller         ###   ########.fr       */
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

	loop = 1;
	init(&env);
	make_grid(&env);
	SDL_RenderPresent(env.renderer);
	while (loop)
	{
		if (SDL_PollEvent(&event) == 1)
			events(event, &loop, &env);
		keyboard_events(&env);
		check_frame();
//		SDL_WarpMouseInWindow(env.window, 1920 / 2, 1080 / 2);
	}
	SDL_DestroyWindow(env.window);
	SDL_Quit();
}

int			main(void)
{
	ft_loop();
	return (EXIT_SUCCESS);
}
