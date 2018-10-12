/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounded_to_mult.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 09:30:13 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/21 11:23:04 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_roundmsup(double nb, int mult)
{
	int n;

	n = (int)ceil(nb);
	while ((n % mult) != 0)
		++n;
	return ((double)n);
}

double	ft_roundminf(double nb, int mult)
{
	int n;

	n = (int)floor(nb);
	while ((n % mult) != 0)
		--n;
	return ((double)n);
}
