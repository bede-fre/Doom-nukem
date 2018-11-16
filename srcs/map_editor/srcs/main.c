/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/15 16:36:37 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** INITIALISATION DE ENV ET LANCEMENT DE LA BOUCLE DES EVENTS
*/

static void	ft_loop(char *file_name)
{
	int			loop;
	t_env		env;
	SDL_Event	event;

	loop = 1;
	init(&env, file_name);
	start_draw(&env);
	while (loop)
	{
		while (SDL_PollEvent(&event))
			events(event, &loop, &env);
		check_frame();
	}
	SDL_RenderClear(env.renderer);
	SDL_DestroyWindow(env.window);
	TTF_CloseFont(env.font);
	TTF_Quit();
	SDL_Quit();
}

int			main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_puterror("usage: ./editor [map_name]");
		return (EXIT_FAILURE);
	}
	ft_loop(av[1]);
	return (EXIT_SUCCESS);
}
