/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:14:15 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/29 14:36:39 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL/SDL.h"
# include "libvect.h"
# include "libft.h"

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define CAP_FPS	60

/*
** COLOR ABGR
*/

# define WHITE_T	(Uint32)0x88FFFFFF
# define WHITE		(Uint32)0xFFFFFFFF
# define GREY		(Uint32)0xFF555555
# define RED		(Uint32)0xFF000099

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

typedef struct		s_bres
{
	int				da;
	int				db;
	int				i;
	int				cpta;
	int				cptb;
	int				cumul;
	int				a;
	int				b;
}					t_bres;

typedef struct		s_draw
{
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}					t_draw;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_grid
{
	unsigned int	scale;
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
void				make_grid(t_env *env, t_draw *draw);
Uint32				set_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void				keyboard_events(t_env *env);
void				check_frame(void);
t_draw				init_draw(t_env *env);
void				uninit_draw(t_draw *draw, t_env *env);
void				clear(t_env *env, t_draw *draw, const char *str, int error);
void				start_draw(t_env *env);
void				fill_px(SDL_Surface *surface, int x, int y, Uint32 col);
void				circle(SDL_Surface *surface, t_point p, int r, Uint32 col);
void				line(SDL_Surface *surface, t_point p1, t_point p2, Uint32 col);

#endif
