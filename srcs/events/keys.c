/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:42:46 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/08 16:33:32 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int		get_key_id(t_doom *doom, int keycode)
{
	if (keycode == doom->bindings[K_FORWARD])
		return (K_FORWARD);
	if (keycode == doom->bindings[K_BACKWARD])
		return (K_BACKWARD);
	if (keycode == doom->bindings[K_LEFT])
		return (K_LEFT);
	if (keycode == doom->bindings[K_RIGHT])
		return (K_RIGHT);
	return (-1);
}

void			key_init(t_doom *doom)
{
	doom->keys = (char*)ft_memalloc(sizeof(char) * K_END);
	doom->bindings = (int*)ft_memalloc(sizeof(int) * K_END);
	doom->bindings[K_FORWARD] = 13;
	doom->bindings[K_BACKWARD] = 1;
	doom->bindings[K_LEFT] = 0;
	doom->bindings[K_RIGHT] = 2;
}

char			is_key_pressed(t_doom *doom, int key)
{
	if (key > 0 && key < K_END)
		return (doom->keys[key]);
	return (0);
}

int				key_pressed(int key, void *param)
{
	int			index;

	if ((index = get_key_id((t_doom*)param, key)) != -1)
		((t_doom*)param)->keys[index] = 1;
	if (key == 53)
		exit(0);
	render(param);
	return (0);
}

int				key_released(int key, void *param)
{
	int			index;

	if ((index = get_key_id((t_doom*)param, key)) != -1)
		((t_doom*)param)->keys[index] = 0;
	return (0);
}
