/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_game_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:01:09 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/07 17:52:32 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	print_in_game_message(t_all *all)
{
	if (all->message)
	{
		mlx_string_put(all->ptr.mlx, all->ptr.win, WINX / 2, WINY / 2,
			RED, "OPEN YOU BITCH !");
		all->message_spd -= MSG_SPEED;
		all->message = (all->message_spd <= 0.0f) ? FALSE : TRUE;
	}
}
