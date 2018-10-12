/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:56:30 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/15 17:47:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s != NULL)
	{
		if (!(str = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
			return (NULL);
		i = -1;
		while (s[++i])
			str[i] = (*f)((char)s[i]);
		str[i] = '\0';
		return (str);
	}
	return (0);
}
