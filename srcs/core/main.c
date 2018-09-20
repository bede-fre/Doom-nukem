/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:32:23 by toliver           #+#    #+#             */
/*   Updated: 2018/09/20 17:32:25 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void			init(void)
{
	t_doom			*doom;

	doom = (t_doom*)ft_memalloc(sizeof(t_doom));
	if (!(doom->mlx = mlx_init()))
		ft_error("Failed to initalize the mlx");
	if (!(doom->window = mlx_new_window(doom->mlx, WIN_WIDTH,
	WIN_HEIGHT, "doom-nukem")))
		ft_error("MLX failed to create a window");
	mlx_clear_window(doom->mlx, doom->window);
	loop(doom);
}

int					blueskintest(void) // a supprimer apres
{
	ft_printvector(ft_2dintersection(ft_linedef(ft_vecdef(2, 2, 0), ft_vecdef(6, 10, 0)),ft_linedef(ft_vecdef(-10, 4, 0), ft_vecdef(12, 25, 0))));
	printf("longueur = %f\n", ft_2dvecnorm(ft_vecsub(ft_vecdef(2, 2, 0), ft_vecdef(2, 2, 0))));
	printf("longueur = %f\n", ft_2dvecnorm(ft_vecsub(ft_2dintersection(ft_linedef(ft_vecdef(2, 2, 0), ft_vecdef(6, 10, 0)),ft_linedef(ft_vecdef(-10, 4, 0), ft_vecdef(12, 25, 0))), ft_vecdef(2, 2, 0))));
	return (1);
}

int					main(void)
{
//	init();
	blueskintest();
	return (0);
}
