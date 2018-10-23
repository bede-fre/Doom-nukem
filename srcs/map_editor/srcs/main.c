/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:18:35 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/23 14:16:47 by lguiller         ###   ########.fr       */
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
	t_mat3 test;
	SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL
	SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, 0u); // Ouverture de la fenêtre
	plop(); // Mise en pause du programme
	SDL_Quit(); // Arrêt de la SDL
	test = ft_vecdef(0.0f, 1.0f, 2.0f);
	printf("%f, %f %f\n", test.x, test.y, test.z);
	return EXIT_SUCCESS; // Fermeture du programme
}
