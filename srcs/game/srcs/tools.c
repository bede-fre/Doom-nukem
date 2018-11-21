/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:17:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/21 10:46:21 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int to_win(int x)
{
	return (x * BLOCK_SIZE / ZOOM);
}

int	to_map(double x)
{
	return ((int)(x / BLOCK_SIZE));
}

int	is_wall(char wall)
{
	return (wall == 'A' || wall == 'B' || wall == 'C' || wall == 'D');
}
