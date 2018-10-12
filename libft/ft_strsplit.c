/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:52:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/16 11:33:10 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cut(char *s, char c)
{
	int i;
	int cut;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		++i;
	if (s[i] == '\0')
		return (0);
	cut = 0;
	while (s[i] != 0)
	{
		if (s[i] == c && (s[i + 1] != '\0' && s[i + 1] != c))
			++cut;
		++i;
	}
	++cut;
	return (cut);
}

static int		leng(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_cut((char *)s, c) + 1))))
		return (NULL);
	k = ft_cut((char *)s, c);
	i = -1;
	while (++i < k)
	{
		while (*s == c && *s != '\0')
			s++;
		j = 0;
		if (!(tab[i] = (char*)malloc(sizeof(char) * (leng((char *)s, c) + 1))))
			return (0);
		while (*s != c && *s != '\0')
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
