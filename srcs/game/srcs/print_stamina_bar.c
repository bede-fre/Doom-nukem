/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stamina_bar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:45:17 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/22 16:43:38 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"


/*static void	print_border(t_img *img)
{
	t_point		p;
	const int	size = 3;

	p.y = -1;
	while (++p.y < BARH)
	{
		p.x = -1;
		while (++p.x < BARW)
			if (p.x <= size || p.x >= BARW - size - 1 || p.y <= size
				|| p.y >= BARH - size - 1)
				ft_fill_pixel(img, p.x, p.y, GREY_A);
	}
}*/

void		print_stamina_bar(t_img *img, int stamina)
{
	const int	rate = 125;
	const int	size = 2;
	t_point		p;

	(void)stamina;
	p.y = -1;
	while (++p.y < BARH)
	{
		p.x = -1;
		while (++p.x < BARW)
		{
			if (p.x <= size || p.x >= BARW - size - 1 || p.y <= size
				|| p.y >= BARH - size - 1)
				ft_fill_pixel(img, p.x, p.y, BLACK);
			else if (p.x < rate)
				ft_fill_pixel(img, p.x, p.y, GREEN_A);
			else
				ft_fill_pixel(img, p.x, p.y, ALPHA);
		}
	}
}
