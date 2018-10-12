/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 10:14:42 by bede-fre          #+#    #+#             */
/*   Updated: 2018/06/01 14:28:24 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return ((int)(a << 24) | (int)(r << 16) | (int)(g << 8) | (int)b);
}
