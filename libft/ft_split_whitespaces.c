/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:36:42 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/05 15:45:49 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		wrd_length(const char *s)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]) && s[i])
			++i;
		if (!s[i])
			return (count);
		while (!ft_isspace(s[i]) && s[i])
			++i;
		count++;
	}
	return (count);
}

static int		leng(char *s)
{
	int i;

	i = 0;
	while (!ft_isspace(s[i]) && s[i])
		i++;
	return (i);
}

char			**ft_split_whitespaces(char const *s)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if ((s == NULL)
	|| !(tab = (char**)malloc(sizeof(char*) * (wrd_length((char *)s) + 1))))
		return (NULL);
	k = wrd_length((char *)s);
	i = -1;
	while (++i < k)
	{
		while (ft_isspace(*s) && *s != '\0')
			s++;
		if (!(tab[i] = (char*)malloc(sizeof(char) * (leng((char *)s) + 1))))
			return (0);
		j = 0;
		while (!ft_isspace(*s) && *s != '\0')
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
