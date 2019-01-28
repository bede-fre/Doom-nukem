/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:00:16 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:55:58 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lowercase(const char *str)
{
	char	*tmp;
	int		i;

	if (!str || !(tmp = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = -1;
	while (str[++i])
		tmp[i] = ft_tolower(str[i]);
	return (tmp);
}

char	*ft_uppercase(const char *str)
{
	char	*tmp;
	int		i;

	if (!str || !(tmp = ft_strnew(ft_strlen(str))))
		return (NULL);
	i = -1;
	while (str[++i])
		tmp[i] = ft_toupper(str[i]);
	return (tmp);
}
