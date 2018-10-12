/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:59:06 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/08 18:56:33 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	car;
	int		i;

	str = (char *)s;
	car = (const char)c;
	i = 0;
	if (s[i] == '\0' && car == '\0')
		return (str);
	while (s[i])
	{
		if (s[i] == car)
			return (str + i);
		if (s[i + 1] == car)
			return (str + (i + 1));
		++i;
	}
	return (NULL);
}
