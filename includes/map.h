/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:29:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/16 13:42:19 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "doom.h"

# define MAP_WIDTH 200
# define MAP_HEIGHT 200

typedef struct		s_wall
{
	int				num;
	int				nextzone;
	t_vec			origin;
	struct s_wall	*next;
}					t_wall;

typedef struct		s_zone
{
	int				num;
	t_wall			*wall;
	struct s_zone	*next;
}					t_zone;

void				sort_list(t_zone *zone);
void				make_circular_lst(t_zone *zone);

#endif
