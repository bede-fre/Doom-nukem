/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:14:15 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/23 16:34:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL/SDL.h"
# include "libvect.h"
# include "libft.h"

typedef struct		s_img
{
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Surface		*surface;
}					t_img;

typedef struct	s_env
{
	SDL_Window	*window;
	t_img		*img;
}				t_env;

void			init(t_env *env);
void			events(SDL_Event event, int *loop);

#endif
