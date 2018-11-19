/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 09:14:15 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/19 14:25:45 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "libvect.h"
# include "libft.h"

# define WIN_DIM	20
# define WIN_WIDTH	WIN_HEIGHT + 18 * SCALE
# define WIN_HEIGHT	(MAP_HEIGHT + 2) * WIN_DIM
# define MAP_WIDTH	32
# define MAP_HEIGHT	32
# define SCALE		(int)((double)WIN_HEIGHT / (double)(MAP_HEIGHT + 2))
# define GAP		SCALE
# define CAP_FPS	60
# define START		's'
# define FLOOR		' '
# define SECRET		'2'
# define TP_S		'3'
# define TP_E		'4'
# define T_A		'A'
# define T_B		'B'
# define T_C		'C'
# define T_D		'D'
# define T_AS		'a'
# define T_BS		'b'
# define T_CS		'c'
# define T_DS		'd'
# define TRUE		1
# define FALSE		0
# define TEXT_A		"./srcs/map_editor/textures/wood1.xpm"
# define TEXT_B		"./srcs/map_editor/textures/metal1.xpm"
# define TEXT_C		"./srcs/map_editor/textures/stone1.xpm"
# define TEXT_D		"./srcs/map_editor/textures/ice1.xpm"
# define ERASER		"/srcs/map_editor/textures/eraser.jpg"
# define FONT		"/srcs/map_editor/font/times-new-roman.ttf"

/*
** COLOR RGBA
*/

# define BLACK		(Uint32)0x000000FF
# define WHITE		(Uint32)0xFFFFFFFF
# define GREY		(Uint32)0x555555FF
# define RED		(Uint32)0x990000FF
# define GREEN		(Uint32)0x009900FF
# define LIGHT_GREY	(Uint32)0x999999FF
# define START_COL	RED
# define T_A_COL	(Uint32)0x844927FF
# define T_B_COL	(Uint32)0xF3A16AFF
# define T_C_COL	(Uint32)0x7E878BFF
# define T_D_COL	(Uint32)0x499BC4FF
# define T_AS_COL	(Uint32)0xB87C5AFF
# define T_BS_COL	(Uint32)0xF5C19FFF
# define T_CS_COL	(Uint32)0xC0C5C8FF
# define T_DS_COL	(Uint32)0x86D1F7FF
# define SECRET_COL	(Uint32)0x888888FF
# define TP_S_COL	(Uint32)0xAAFFAAFF
# define TP_E_COL	(Uint32)0x00FF00FF

enum				e_keys
{
	K_RESET = 0,
	K_RENDER,
	K_QUIT,
	K_ESPACE,
	B_LEFT,
	B_RIGHT,
	K_END
};

enum				e_button
{
	WOOD = 0,
	METAL,
	STONE,
	ICE,
	COLISION,
	NO_COLISION,
	TP_START,
	TP_END,
	B_START,
	B_ERASER
};

typedef struct		s_parse
{
	char			*buff;
	char			fd;
	short			i;
}					t_parse;

typedef struct		s_textures
{
	SDL_Texture		*t_a;
	SDL_Texture		*t_b;
	SDL_Texture		*t_c;
	SDL_Texture		*t_d;
	SDL_Texture		*eraser;
}					t_textures;

typedef struct		s_button
{
	t_point			pos;
	t_point			size;
	SDL_Rect		rect;
	int				button_col;
	int				border_col;
	SDL_Texture		*texture;
}					t_button;

typedef struct		s_env
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	TTF_Font		*font;
	t_textures		text;
	char			map[MAP_HEIGHT][MAP_WIDTH];
	int				*bindings;
	int				*keys;
	t_point			mouse;
	char			*file_name;
	char			object;
	int				colision;
	t_button		buttons[10];
}					t_env;

void				init(t_env *env, char *file_name);
void				events(SDL_Event event, int *loop, t_env *env);
void				refresh_events(t_env *env);
void				check_frame(void);
SDL_Surface			*init_surface(t_env *env);
void				create_texture(SDL_Surface *surface, t_env *env);
void				clear(t_env *env, const char *str, int error);
void				start_draw(t_env *env);
void				fill_px(SDL_Surface *surface, int x, int y, Uint32 col);
void				make_grid(SDL_Surface *surface);
void				read_file(char *name, char (*map)[MAP_HEIGHT][MAP_WIDTH]);
void				fill_rect(SDL_Surface *surface, t_point coord, Uint32 col);
void				fill_border(SDL_Surface *surface, t_point coord, int l,
						Uint32 col);
void				fill_cross(SDL_Surface *surface, t_point coord, Uint32 col);
void				print_map(SDL_Surface *surface,
						char map[MAP_HEIGHT][MAP_WIDTH]);
int					map_to_win(int x);
int					win_to_map(int x);
void				modif_map(t_env *env);
void				write_file(char *file_name,
						char map[MAP_HEIGHT][MAP_WIDTH]);
t_point				point_to_map(t_point p);
t_point				point_to_win(t_point p);
void				key_press(SDL_Event event, t_env *env);
void				key_release(SDL_Event event, t_env *env);
void				button_press(SDL_Event event, t_env *env);
void				button_release(SDL_Event event, t_env *env);
void				print_buttons(t_env *env, SDL_Surface *surface,
						char object, int colision);
void				init_button(t_env *env);
void				set_text(SDL_Surface *surface, t_env *env);
SDL_Rect			create_rect(int x, int y, int w, int h);
SDL_Rect			rect_to_map(SDL_Rect rect);
SDL_Rect			rect_to_win(SDL_Rect rect);
int					get_object(char x);
int					get_colision(int x);
char				chose_object(t_button buttons[10], int x, int y,
						int colision);
void				create_new_file(char *file);

#endif
