/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:53:56 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:58:00 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		len;
	size_t	i;

	len = 0;
	while (s1[len] != '\0')
		++len;
	i = 0;
	while (s2[i] != '\0' && i < n)
		s1[len++] = s2[i++];
	s1[len++] = '\0';
	return (s1);
}
