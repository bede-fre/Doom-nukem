/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:43:30 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/16 16:57:14 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_len(char const *s, int i)
{
	int j;

	j = ft_strlen(s);
	--j;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j != 0)
		--j;
	++j;
	if ((j - i) <= 0)
		return (0);
	return (j - i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		k;
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		++i;
	len = ft_len(s, i);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	k = 0;
	if (len > 0)
	{
		while (k < len)
		{
			str[k] = s[i + k];
			++k;
		}
	}
	str[k] = '\0';
	return (str);
}
