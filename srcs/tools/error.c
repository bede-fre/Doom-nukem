/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 15:42:36 by tberthie          #+#    #+#             */
/*   Updated: 2018/10/09 13:57:00 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	ft_error(const char *str)
{
	write(2, ERROR_PREFIX, strlen(ERROR_PREFIX));
	if (!str)
		str = strerror(errno);
	write(2, str, strlen(str));
	write(2, "\n", 1);
	exit(1);
}
