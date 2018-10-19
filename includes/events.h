/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:24:30 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/19 10:14:32 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "doom.h"

enum			e_keys
{
	K_FORWARD = 1,
	K_BACKWARD,
	K_LEFT,
	K_RIGHT,
	K_CTRL,
	K_END
};

typedef struct	s_param
{
	float		sensitivity;
	t_vec		mousepos;
}				t_param;

int				key_pressed(int key, void *param);
int				key_released(int key, void *param);
int				mouse_move(int x, int y, void *param);
int				button_on(int button, int x, int y, void *param);
int				button_off(int button, int x, int y, void *param);
int				window_closed(void *param) __attribute__((noreturn));

#endif
