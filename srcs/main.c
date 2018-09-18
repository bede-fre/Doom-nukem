/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:41:12 by tberthie          #+#    #+#             */
/*   Updated: 2018/09/18 17:27:39 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int					printvec(t_vec a)
{
	printf("x = %f, y = %f, z = %f\n", a.x, a.y, a.z);
	return (1);
}

int					main(int ac)
{
	t_vec			v;
//	ft_error("test");
	v = ft_vecdef(0, 0, 1);
	printvec(v);
	v = ft_vecrot(v, 90, 90, 0);
	printvec(v);
	return (0);
}
