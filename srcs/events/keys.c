/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:42:46 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/18 17:30:46 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void			key_init(t_doom *doom)
{
	doom->keys = (t_key**)ft_memalloc(sizeof(t_key*));
	doom->keys[0] = 0;
}

void			key_add(t_doom *doom, int key)
{

}

char			is_key_pressed(t_doom *doom, int key)
{
	t_key		**keys;

	keys = doom->keys;
	while (*keys)
	{
		if (keys[0]->code == key)
			return (keys[0]->pressed);
		keys++;
	}
	key_add(doom, key);
	return (0);
}

int				key_on(int key, void *param)
{
	// turn on
	return (0);
}

int				key_off(int key, void *param)
{
	// turn off
	return (0);
}
