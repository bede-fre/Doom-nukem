/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:03:39 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (s != NULL)
	{
		if (!(str = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
			return (NULL);
		i = -1;
		while (s[++i])
			str[i] = (*f)((unsigned int)i, (char)s[i]);
		str[i] = '\0';
		return (str);
	}
	return (0);
}
