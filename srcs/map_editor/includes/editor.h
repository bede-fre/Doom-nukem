/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:14:15 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/24 12:09:43 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL/SDL.h"
# include "libvect.h"
# include "libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_grid
{
	unsigned int	scale;
	unsigned int	gap_scale;
	t_point			gap;
}					t_grid;

typedef struct		s_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_grid			grid;
}					t_env;

void				init(t_env *env);
void				events(SDL_Event event, int *loop, t_env *env);
void				set_pixel(SDL_Renderer *renderer, int x, int y, SDL_Color color);
void				make_grid(t_env *env);
void				clear_window(SDL_Renderer *renderer);

#endif
