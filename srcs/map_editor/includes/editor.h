/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:14:15 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/23 15:47:59 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL/SDL.h"
# include "libvect.h"
# include "libft.h"

typedef struct	s_img
{
	int			sl;
	int			bpp;
	int			width;
	int			endian;
	int			height;
	void		*ptr;
	char		*data;
}				t_img;

typedef struct	s_env
{
	SDL_Window	*win;
	t_img		*img;
}				t_env;

void			init(t_env *env);
void			events(SDL_Event event, int *loop);

#endif
