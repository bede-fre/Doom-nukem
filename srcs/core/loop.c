/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:25:08 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/20 16:13:09 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static int				loop_hook(void *param)
{
	render(param);
	return (0);
}

void					loop(t_doom *doom)
{
	key_init(doom);
	mlx_hook(doom->window, 2, 0, &key_pressed, doom);
	mlx_hook(doom->window, 3, 0, &key_released, doom);
	mlx_hook(doom->window, 4, 0, &button_on, doom);
	mlx_hook(doom->window, 5, 0, &button_off, doom);
	mlx_hook(doom->window, 6, 0, &mouse_move, doom);
	mlx_hook(doom->window, 17, 0, &window_closed, doom);
	mlx_loop(doom->mlx);
}
