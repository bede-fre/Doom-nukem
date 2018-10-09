/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:14:16 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/09 13:52:44 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	*ft_memalloc(unsigned int bytes)
{
	void	*ptr;

	ptr = ft_malloc(bytes);
	bzero(ptr, bytes);
	return (ptr);
}

void	*ft_malloc(unsigned int bytes)
{
	void	*ptr;

	if (!(ptr = malloc(bytes)))
		exit(1);
	return (ptr);
}
