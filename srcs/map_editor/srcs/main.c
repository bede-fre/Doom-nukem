/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/12/04 10:11:46 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

static void	print_commands(void)
{
	ft_putchar('\n');
	ft_putendl("		CONTROL CENTER");
	ft_putchar('\n');
	ft_putendl("Esc		--> Quit");
	ft_putendl("Enter		--> Generate");
	ft_putendl("M		--> Mute");
	ft_putendl("L		--> Leaks");
	ft_putchar('\n');
}

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
	print_commands();
	start_draw(&env);
	while (loop)
	{
		while (SDL_PollEvent(&event))
			events(event, &loop, &env);
	}
	SDL_RenderClear(env.renderer);
	SDL_DestroyWindow(env.window);
	TTF_CloseFont(env.font);
	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
}

int			main(int ac, char **av)
{
	if (ac == 2)
		ft_loop(av[1]);
	else if (ac == 3 && av[1][0] == '-' && av[1][1] == 'n' && av[1][2] == '\0')
	{
		create_new_file(av[2]);
		ft_loop(av[2]);
	}
	else
	{
		ft_puterror("usage: ./editor [-n] [map_name]");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
