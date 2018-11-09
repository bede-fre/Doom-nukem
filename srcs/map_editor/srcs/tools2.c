/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:07:53 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/31 10:42:19 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

/*
** CONVERSION DES COORDONNEES DE LA SOURIS RELATIVES A LA FENETRE EN COORDONNEES
** RELATIVES A LA GRILLE
*/

t_point	wind_to_grid(t_env *env, t_point p)
{
	t_point	new_p;
	t_point	transpos;

	transpos = ft_pointdef(env->grid.center.x + env->grid.gap.x,
		env->grid.center.y + env->grid.gap.y);
	new_p.x = (int)roundf((float)(p.x - transpos.x) / (float)env->grid.scale);
	new_p.y = (int)roundf((float)(p.y - transpos.y) / (float)env->grid.scale);
	return (new_p);
}

/*
** CONVERSION DES COORDONNEES DU POINT P RELATIVE A LA POSITION DE LA GRILLE
** EN POSITION RELATIVE A LA FENETRE
*/

t_point	grid_to_wind(t_env *env, t_point p)
{
	t_point	new_p;
	t_point	transpos;

	transpos = ft_pointdef(env->grid.center.x + env->grid.gap.x,
		env->grid.center.y + env->grid.gap.y);
	new_p.x = p.x * env->grid.scale + transpos.x;
	new_p.y = p.y * env->grid.scale + transpos.y;
	return (new_p);
}
