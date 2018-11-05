/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:15:15 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/05 14:58:38 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	check_frame(void)
{
	unsigned int	framedelay;
	int				frame_actual;
	static Uint32	framestart;
	static int		beginsecond;
	static int		nb_frame;

	framedelay = 1000 / CAP_FPS;
	frame_actual = SDL_GetTicks();
	if (beginsecond == 0)
		beginsecond = frame_actual;
	if (frame_actual - beginsecond > 1000)
	{
		ft_putstr("fps = ");
		ft_putnbr(nb_frame);
		ft_putchar('\n');
		nb_frame = 0;
		beginsecond = 0;
	}
	else
		nb_frame++;
	if (framedelay > frame_actual - framestart)
		SDL_Delay(framedelay - (frame_actual - framestart));
	framestart = SDL_GetTicks();
}
