/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:58:04 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/14 09:20:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_calc(int nb, int fd)
{
	if (nb >= 10 || nb <= -10)
	{
		ft_calc(nb / 10, fd);
		ft_calc(nb % 10, fd);
	}
	else if (nb >= 0)
		ft_putchar_fd(nb + '0', fd);
	else
		ft_putchar_fd('0' - nb, fd);
}

void		ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	ft_calc(nb, fd);
}
