/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:07:26 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/30 13:52:40 by lguiller         ###   ########.fr       */
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
** ASSEMBLAGE DES DIFFERENTS TAUX DE COULEUR EN UNE
*/

Uint32		set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/*
** AJOUT D"UNE NOUVELLE COULEUR DANS SURFACE->PIXELS A LA POSITION X Y
*/

void	fill_px(SDL_Surface *surface, int x, int y, Uint32 col)
{
	if (x >= 0 && x < surface->w && y >= 0 && y < surface->h)
		*((Uint32*)(surface->pixels) + x + y * surface->w) = col;
}

/*
** ATTRIBUTION DU X ET Y DANS UN T_POINT
*/

t_point	ft_pointdef(int x, int y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}
