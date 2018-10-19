/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:46:29 by toliver           #+#    #+#             */
/*   Updated: 2018/10/19 10:01:59 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vectors.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_player
{
	t_vec		pos;
	t_vec		head;
	t_vec		body;
	float		speed;
	int			crouched;
}				t_player;

#endif
