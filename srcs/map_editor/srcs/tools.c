/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:07:26 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/24 15:27:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** CHANGEMENT DE LA COULEUR DU PIXEL EN PARAMETRE
*/

void		set_pixel(SDL_Renderer *renderer, int x, int y, SDL_Color color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawPoint(renderer, x, y);
}

/*
** REMPLACEMENT DE TOUT LES PIXELS DE LA FENETRE EN NOIR
*/

void		clear_window(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

SDL_Color	set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}
