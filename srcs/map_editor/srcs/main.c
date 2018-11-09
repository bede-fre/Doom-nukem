/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 14:57:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
**	SDL_WarpMouseInWindow(env.window, 1920 / 2, 1080 / 2);
*/

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
	start_draw(&env);
	while (loop)
	{
		while (SDL_PollEvent(&event))
			events(event, &loop, &env);
		refresh_events(&env);
		check_frame();
	}
	SDL_RenderClear(env.renderer);
	SDL_DestroyWindow(env.window);
	SDL_Quit();
}

int			main(void)
{
	ft_loop();
	return (EXIT_SUCCESS);
}
