/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:36:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/05 17:51:30 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	if (!(mem = (void *)malloc(sizeof(void) * size)))
		exit(-1);
	i = -1;
	while (++i < size)
		*(char *)(mem + i) = 0;
	return (mem);
}
