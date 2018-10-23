/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/23 13:06:38 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*void	init(t_env *env)
{


}*/
/*
int	main(void)
{
//	t_env	env;

//	init(&env);
	SDL_Init(SDL_INIT_VIDEO);

	SDL_SetVideoMode(1920, 1080, 32, SDL_RESIZABLE);

	SDL_Quit();
	return (0);
}*/

static void plop(void)
{
	int	continuer = 1;
	SDL_Event event;
	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
		}
	}
}

int main(void)
{
	SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
	SDL_CreateWindow("Test", 200, 200, 1920, 1080, 0); // Ouverture de la fenêtre
	plop(); // Mise en pause du programme
	SDL_Quit(); // Arrêt de la SDL
	return EXIT_SUCCESS; // Fermeture du programme
}
