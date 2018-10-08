/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:51:17 by toliver           #+#    #+#             */
/*   Updated: 2018/10/08 16:29:15 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include "vectors.h"

# include "mlx.h"

# include "vectors.h"
# include "map.h"
# include "keys.h"
# include "image.h"
# include "player.h"

# define ERROR_PREFIX	"./doom-nukem: "

# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080
# define CLIPPING		1
# define FOV			60.0

// T_DOOM

typedef struct			s_param
{
	float				sensitivity;
	t_vec				mousepos;
}						t_param;

typedef struct			s_player
{
	t_vec				pos;
	t_vec				rot;
	t_vec				rotangle;
	float				speed;
}						t_player;

typedef struct			s_doom
{
	void				*mlx;
	void				*window;

	int					*bindings;
	char				*keys;

	t_img				img;
	t_img				view;
	t_img				map;
	t_img				minimap;

	int					angle;

	t_player			player;
	t_param				param;
	t_zone				**zones;

}						t_doom;

// CORE

void					loop(t_doom *doom);
void					render(t_doom *doom);

// EVENTS

int						key_pressed(int key, void *param);
int						key_released(int key, void *param);
void					key_init(t_doom *doom);
char					is_key_pressed(t_doom *doom, int key);

int						button_on(int button, int x, int y, void *param);
int						button_off(int button, int x, int y, void *param);
int						mouse_move(int x, int y, void *param);
int						window_closed(void *param) __attribute((noreturn));

// TOOLS

void					*ft_malloc(unsigned int bytes);
void					*ft_memalloc(unsigned int bytes);
void					ft_error(const char *str) __attribute((noreturn));
t_wall					*get_wall(char type, int nextzone, t_vec o, t_vec d);
void					mapimgalloc(t_zone **zones, t_img *map, t_doom *env);

void					merge_images(t_img *dest, t_img *src, int x, int y); // penser a l'alpha
int						px_to_img(t_img *img, int x, int y, int c); // penser a l'alpha
void					img_get(t_img *ing, int x, int y, t_doom *env);

void					rotmapimgalloc(t_zone **zones, t_img *map, t_doom *env);


// DRAWING

void					ft_putline(t_vec a, t_vec b, t_img *img, int color);

// PLAYER HANDLING

int						playerrot(t_doom *env, t_vec diff);
int						playermove(t_doom *env);

#endif
