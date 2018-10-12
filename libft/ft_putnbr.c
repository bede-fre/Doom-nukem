/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 08:39:32 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/08 15:18:30 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_calc(int nb)
{
	if (nb >= 10 || nb <= -10)
	{
		ft_calc(nb / 10);
		ft_calc(nb % 10);
	}
	else if (nb >= 0)
		ft_putchar(nb + '0');
	else
		ft_putchar('0' - nb);
}

void		ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	ft_calc(nb);
}
