/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/15 17:47:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (s == NULL)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		dst[i] = s[start];
		++i;
		++start;
	}
	dst[i] = '\0';
	return (dst);
}
