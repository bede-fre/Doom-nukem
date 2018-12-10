/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_game_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:01:09 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/10 09:43:40 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	print_in_game_message(t_all *all)
{
	if (all->msg_door)
	{
		mlx_string_put(all->ptr.mlx, all->ptr.win, WINX / 2, WINY / 2,
			RED, "DOOR OPENED !");
		all->msg_door_rate -= MSG_SPEED;
		all->msg_door = (all->msg_door_rate <= 0.0f) ? FALSE : TRUE;
	}
	if (all->msg_tp)
	{
		mlx_string_put(all->ptr.mlx, all->ptr.win, WINX / 2, WINY / 2 - 50,
			RED, "WARPED !");
		all->msg_tp_rate -= MSG_SPEED;
		all->msg_tp = (all->msg_tp_rate <= 0.0f) ? FALSE : TRUE;
	}
}
