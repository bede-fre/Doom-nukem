/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:51:17 by toliver           #+#    #+#             */
/*   Updated: 2018/09/20 19:51:23 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
#define DOOM_H

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "vectors.h"

#include "mlx.h"

#include "vectors.h"
#include "map.h"
#include "keys.h"

#define ERROR_PREFIX	"./doom-nukem: "

#define WIN_WIDTH		1920
#define WIN_HEIGHT		1080

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
	float				speed;
}						t_player;

typedef struct			s_doom
{
	void				*mlx;
	void				*window;

	int					*bindings;
	char				*keys;

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

void					merge_images(t_img *dest, t_img *src, int x, int y);

#endif
