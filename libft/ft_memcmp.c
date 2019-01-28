/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:15:59 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:04 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		value;

	value = 0;
	i = -1;
	while (++i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
		{
			value = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
			return (value);
		}
	}
	return (value);
}
