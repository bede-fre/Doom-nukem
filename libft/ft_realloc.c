/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:04:12 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:43 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_realloc(void *str, size_t size)
{
	void	*tmp;

	if (size == 0 && str)
	{
		ft_memdel(&str);
		str = ft_memalloc(1);
	}
	else if (size > 0)
	{
		tmp = str;
		str = ft_memalloc(size);
		if (tmp)
		{
			ft_strncpy(str, tmp, size);
			ft_memdel((void **)&tmp);
		}
	}
	return (str);
}
