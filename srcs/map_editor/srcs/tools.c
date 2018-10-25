/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:07:26 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/25 10:45:35 by lguiller         ###   ########.fr       */
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
