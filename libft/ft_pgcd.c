/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:34:53 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:33 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_pgcd(unsigned int a, unsigned int b)
{
	int i;

	i = (a <= b) ? a : b;
	while (i > 0)
	{
		if ((a % i) == 0 && (b % i) == 0)
			return (i);
		--i;
	}
	return (0);
}
