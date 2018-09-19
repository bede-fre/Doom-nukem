/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:33:26 by toliver           #+#    #+#             */
/*   Updated: 2018/09/18 17:40:05 by toliver          ###   ########.fr       */
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

typedef struct			s_doom
{
	void				*mlx;
	void				*window;

	t_key				**keys;

	t_zone				**zones;

}						t_doom;


// CORE

void					loop(t_doom *doom);
void					render(t_doom *doom);

// EVENTS

void					key_init(t_doom *doom);
int						key_on(int key, void *param);
int						key_off(int key, void *param);
int						button_on(int button, int x, int y, void *param);
int						button_off(int button, int x, int y, void *param);
int						mouse_move(int button, int x, int y, void *param);
int						window_closed(void *param) __attribute((noreturn));

// TOOLS

void					*ft_malloc(unsigned int bytes);
void					*ft_memalloc(unsigned int bytes);
void					ft_error(const char *str) __attribute((noreturn));

#endif
