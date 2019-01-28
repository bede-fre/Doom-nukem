/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:32:54 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:52 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strcspn(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		j = -1;
		while (s2[++j])
			if (s1[i] == s2[j])
				return (i);
		++i;
	}
	return (i);
}
