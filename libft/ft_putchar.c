/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:26:36 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_print(char c)
{
	write(1, &c, 1);
}

void		ft_putchar(int c)
{
	if (c >= 16777215)
	{
		ft_print((char)(c >> 24));
		ft_print((char)(c >> 16));
		ft_print((char)(c >> 8));
		ft_print((char)c);
	}
	else if (c >= 65535)
	{
		ft_print((char)(c >> 16));
		ft_print((char)(c >> 8));
		ft_print((char)c);
	}
	else if (c >= 255)
	{
		ft_print((char)(c >> 8));
		ft_print((char)c);
	}
	else
		ft_print((char)c);
}
