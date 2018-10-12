/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 10:10:33 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/25 10:16:41 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int	ft_puthex(unsigned char c)
{
	char *tab;

	tab = "0123456789abcdef";
	ft_putchar(tab[c / 16]);
	ft_putchar(tab[c % 16]);
	return (1);
}

static void	print_line(unsigned char *str, size_t start, size_t max)
{
	size_t i;

	i = start - 1;
	while (++i < (start + 16) && i < max && ft_puthex(str[i]))
		if (i % 2)
			ft_putchar(' ');
	while (i < (start + 16))
	{
		ft_putstr("  ");
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	i = start - 1;
	while (++i < (start + 16) && i < max)
		ft_putchar(ft_isprint(str[i]) ? str[i] : '.');
	ft_putchar('\n');
}

void		print_memory(const void *addr, size_t size)
{
	unsigned char	*str;
	size_t			c;

	str = (unsigned char *)addr;
	c = -16;
	while ((c += 16) < size)
		print_line(str, c, size);
}
