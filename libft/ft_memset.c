/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:18:07 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	car;
	size_t			i;

	str = (unsigned char *)b;
	car = (unsigned char)c;
	i = -1;
	while (++i < len)
		*(str + i) = car;
	return (b);
}
