/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:43:48 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/12 11:24:12 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	modif_map(t_env *env)
{
	t_point	i;

	i = ft_pointdef(win_to_map(env->mouse.x), win_to_map(env->mouse.y));
	if (i.x >= 0 && i.x < MAP_WIDTH && i.y >= 0 && i.y < MAP_HEIGHT &&
		env->map[i.y][i.x] != env->object)
		env->map[i.y][i.x] = env->object;
}
