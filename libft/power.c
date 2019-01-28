/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:14:48 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:58:18 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nbr, int power)
{
	int value;
	int i;

	value = 1;
	i = -1;
	while (++i < power)
		value *= nbr;
	return (value);
}

double	ft_fpow(double nbr, int power)
{
	int value;
	int i;

	value = 1.0;
	i = -1;
	while (++i < power)
		value *= nbr;
	return (value);
}
