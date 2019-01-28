/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:40:27 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:03 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_bis;
	unsigned char	*src_bis;
	size_t			i;

	dst_bis = (unsigned char *)dst;
	src_bis = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_bis[i] = src_bis[i];
		if (src_bis[i] == (unsigned char)c)
			return (dst + (i + 1));
		++i;
	}
	return (NULL);
}
