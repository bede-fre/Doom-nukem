/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_game_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:01:09 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/07 16:29:48 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	print_in_game_message(t_all *all)
{
	if (all->message)
	{
		printf("%f\n", all->message_spd );
		mlx_string_put(all->ptr.mlx, all->ptr.win, WINX/2, WINY/2, 0xff0000, "you open a door");
		all->message_spd -= MSG_SPEED;
		all->message = (all->message_spd <= 0.0f) ? FALSE : TRUE;
	}
	else if (all->keys_tab[KEY_F] && all->message_spd <= 0.1f)
	{
		all->message = TRUE;
		mlx_string_put(all->ptr.mlx, all->ptr.win, WINX/2, WINY/2, 0xff0000, "you open a door");
		all->message_spd = 1.0f;
	}
}
