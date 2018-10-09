/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:22:18 by toliver           #+#    #+#             */
/*   Updated: 2018/10/09 16:12:09 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	errset1(int *err, float *x, int difinc1, int difinc2)
{
	*err -= difinc1;
	*x += (float)difinc2;
}

static void	errset2(int *err, float *y, int difinc0, int difinc3)
{
	*err += difinc0;
	*y += (float)difinc3;
}

void		ft_putline(t_vec a, t_vec b, t_img *img, int color)
{
	int	difinc[4];
	int	err;
	int	err2;

	difinc[0] = abs((int)roundf(b.x) - (int)roundf(a.x));
	difinc[1] = abs((int)roundf(b.y) - (int)roundf(a.y));
	difinc[2] = (int)roundf(a.x) < (int)roundf(b.x) ? 1 : -1;
	difinc[3] = (int)roundf(a.y) < (int)roundf(b.y) ? 1 : -1;
	err = (difinc[0] > difinc[1] ? difinc[0] : -difinc[1]) / 2;
	err2 = 0;
	while (42)
	{
		px_to_img(img, a.x, a.y, color);
		if ((int)roundf(a.x) == (int)roundf(b.x) &&
			(int)roundf(a.y) == (int)roundf(b.y))
			break ;
		err2 = err;
		if (err2 > -difinc[0])
			errset1(&err, &a.x, difinc[1], difinc[2]);
		if (err2 < difinc[1])
			errset2(&err, &a.y, difinc[0], difinc[3]);
	}
}
