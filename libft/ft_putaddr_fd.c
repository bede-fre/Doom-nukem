/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:50:51 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/11 16:04:17 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putaddr_fd(void *str, int fd)
{
	long int			div;
	char				tmp;
	unsigned long int	n;

	n = (unsigned long int)str;
	div = 16;
	write(fd, "0x", 2);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		tmp = '0' + n / div;
		if (tmp > '9')
		{
			tmp += 39;
			write(fd, &tmp, 1);
		}
		else
			write(fd, &tmp, 1);
		n %= div;
		div /= 16;
	}
}
