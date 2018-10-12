/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:13:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/08 18:48:42 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_dst;
	char	*str_src;
	size_t	i;

	str_dst = (char *)dst;
	str_src = (char *)src;
	i = -1;
	if (str_src > str_dst)
		while (++i < len)
			*(str_dst + i) = *(str_src + i);
	else
		while (0 <= (long int)(--len))
			*(str_dst + len) = *(str_src + len);
	return (dst);
}
