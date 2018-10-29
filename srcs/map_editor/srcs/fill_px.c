/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:12:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 13:38:49 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** AJOUT D"UNE NOUVELLE COULEUR DANS SURFACE->PIXELS A LA POSITION X Y
*/

void	fill_px(SDL_Surface *surface, int x, int y, Uint32 col)
{
	if (x >= 0 && x < surface->w && y >= 0 && y < surface->h)
		*((Uint32*)(surface->pixels) + x + y * surface->w) = col;
}
