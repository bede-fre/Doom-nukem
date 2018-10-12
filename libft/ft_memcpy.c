/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:09:55 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/15 10:05:10 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str_dst;
	char	*str_src;
	size_t	i;

	str_dst = (char *)dst;
	str_src = (char *)src;
	i = -1;
	while (++i < n)
		*(str_dst + i) = *(str_src + i);
	return (str_dst);
}
