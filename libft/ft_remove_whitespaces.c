/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_whitespaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:42:28 by bede-fre          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:44 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_remove_whitespaces(char *str)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (str[++i])
	{
		j = i;
		tmp = i;
		while (ft_isspace(str[j]))
			++j;
		while (str[j])
		{
			str[tmp] = str[j];
			++tmp;
			++j;
		}
		while (str[tmp])
		{
			str[tmp] = '\0';
			++tmp;
		}
	}
}
