/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:51:17 by toliver           #+#    #+#             */
/*   Updated: 2018/10/09 16:08:44 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# include "mlx.h"
# include "vectors.h"
# include "map.h"
# include "events.h"
# include "image.h"
# include "player.h"

# define ERROR_PREFIX	"./doom-nukem: "

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define CLIPPING	1
# define FOV		60.0

// T_DOOM

typedef struct	s_doom
{
	int			angle;
	int			*bindings;
	void		*mlx;
	void		*window;
	char		*keys;
	t_img		img;
	t_img		map;
	t_img		minimap;
	t_zone		**zones;
	t_param		param;
	t_player	player;
}				t_doom;

// CORE

void			init(t_doom **env);
void			loop(t_doom *doom);
void			render(t_doom *doom);

// EVENTS

void			key_init(t_doom *doom);
char			is_key_pressed(t_doom *doom, int key);

// TOOLS

void			*ft_malloc(unsigned int bytes);
void			*ft_memalloc(unsigned int bytes);
void			px_to_img(t_img *img, int x, int y, int c);
void			img_get(t_img *ing, int x, int y, t_doom *env);
void			ft_error(const char *str) __attribute__((noreturn));
void			merge_images(t_img *dest, t_img *src, int x, int y); // penser a l'alpha
void			mapimgalloc(t_zone **zones, t_img *map, t_doom *env);
void			rotmapimgalloc(t_zone **zones, t_img *map, t_doom *env);
t_wall			*get_wall(char type, int nextzone, t_vec o, t_vec d);

// DRAWING

void			ft_putline(t_vec a, t_vec b, t_img *img, int color);

// PLAYER HANDLING

int				playermove(t_doom *env);
int				playerrot(t_doom *env, t_vec diff);

#endif
