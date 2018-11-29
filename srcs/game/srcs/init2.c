/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:56:49 by cmace             #+#    #+#             */
/*   Updated: 2018/11/29 14:43:26 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void		ft_init_sdl(t_all *all)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		exit(0);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		exit(0);
	init_sounds(all);
}

void		init_sounds(t_all *all)
{
	if ((all->musics.musics = Mix_LoadMUS(M_WOAH)) == NULL)
		ft_puterror(Mix_GetError());
	if ((all->sounds.opendoor = Mix_LoadWAV(S_OPENDOOR)) == NULL)
		ft_puterror(Mix_GetError());
	if ((all->sounds.closedoor = Mix_LoadWAV(S_CLOSEDOOR)) == NULL)
		ft_puterror(Mix_GetError());
	if ((all->sounds.teleport = Mix_LoadWAV(S_TELEPORT)) == NULL)
		ft_puterror(Mix_GetError());
	if ((all->musics.win = Mix_LoadMUS(S_WIN)) == NULL)
		ft_puterror(Mix_GetError());
}

void		init_sprites(t_all *all, t_sprites *sprites)
{

	(void)all;
	(void)sprites;
	//	init_xpm(all->ptr, &sprites->spr_barrel, SPR_BARREL);
}
