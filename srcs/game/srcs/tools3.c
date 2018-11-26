/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:12:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/26 20:33:52 by cmace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	display_map(char map[MAPY][MAPX])
{
	int i;
	int j;

	i = 0;
	while (i < MAPY)
	{
		j = 0;
		while (j < MAPX)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}