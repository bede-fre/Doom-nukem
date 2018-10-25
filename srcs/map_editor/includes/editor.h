/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:14:15 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/25 10:43:20 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL/SDL.h"
# include "libvect.h"
# include "libft.h"

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

enum				e_keys
{
	K_UP = 0,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_ZOOMIN,
	K_ZOOMOUT,
	K_RESET,
	K_QUIT,
	K_END
};

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_grid
{
	unsigned int	scale;
	unsigned int	gap_scale;
	t_point			center;
	t_point			gap;
}					t_grid;

typedef struct		s_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_grid			grid;
	int				*bindings;
	int				*keys;
}					t_env;

void				init(t_env *env);
void				events(SDL_Event event, int *loop, t_env *env);
void				set_pixel(SDL_Renderer *renderer, int x, int y,
						SDL_Color color);
void				make_grid(t_env *env);
Uint32				set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void				keyboard_events(t_env *env);

#endif
