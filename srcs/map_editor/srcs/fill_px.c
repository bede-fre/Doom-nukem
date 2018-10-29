/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:12:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/29 13:21:39 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** AJOUT D"UNE NOUVELLE COULEUR DANS SURFACE->PIXELS A LA POSITION X Y
*/

void	fill_px(SDL_Surface *surface, t_point p, Uint32 col)
{
	if (p.x >= 0 && p.x < surface->w && p.y >= 0 && p.y < surface->h)
		*((Uint32*)(surface->pixels) + p.x + p.y * surface->w) = col;
}
