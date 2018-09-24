/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:29:52 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/24 15:22:41 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct			s_wall
{
	char				type; // clip / noclip / ...?

	int					nextzone;
	t_vec				origin;
	t_vec				direction;

}						t_wall;

typedef struct			s_zone
{
	t_wall				**walls;

}						t_zone;

#endif
