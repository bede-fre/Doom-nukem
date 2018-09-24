/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:32:23 by toliver           #+#    #+#             */
/*   Updated: 2018/09/24 17:51:00 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

t_wall				*wall(char type, int nextzone, t_vec origin, t_vec dir)
{
	t_wall			*ptr;

	ptr = (t_wall*)ft_memalloc(sizeof(t_wall));
	ptr->type = type;
	ptr->nextzone = nextzone;
	ptr->origin = origin;
	ptr->direction = dir;
	return (ptr);
}

t_zone				*malloczonetest(void)
{
	t_zone			*zone;

	zone = (t_zone*)ft_memalloc(sizeof(t_zone));
	zone->walls = (t_wall**)ft_memalloc(sizeof(t_wall*) * 5);
	zone->walls[0] = wall(0, -1, ft_vecdef(0, 0, 0), ft_vecdef(1, 0, 0));
	zone->walls[1] = wall(0, -1, ft_vecdef(20, 0, 0), ft_vecdef(0, 1, 0));
	zone->walls[2] = wall(0, -1, ft_vecdef(20, 20, 0), ft_vecdef(20, -1, 0));
	zone->walls[3] = wall(0, -1, ft_vecdef(0, 20, 0), ft_vecdef(-1, 0, 0));
	zone->walls[4] = NULL;
	return (zone);
}

static void			mapinit(t_doom *env)
{
	env->zones = (t_zone**)malloc(sizeof(t_zone*) * 2);
	env->zones[1] = NULL;
	env->zones[0] = malloczonetest();
}

static void			playerinit(t_doom *env)
{
	env->player.pos = ft_vecdef(10, 10, 0);
	env->player.rot = ft_vecdef(0, -1, 0);
	env->player.speed = 0.1;
}

static void			imginit(t_doom *env)
{
	if (!(env->img.ptr = mlx_new_image(env->mlx, WIN_WIDTH, WIN_HEIGHT)))
		exit (1);
	if (!(env->img.data = mlx_get_data_addr(env->img.ptr, &(env->img.bpp),
			&(env->img.linesize), &(env->img.endian))))
		exit (1);
	env->img.width = WIN_WIDTH;
	env->img.height = WIN_HEIGHT;
}

static void			init(t_doom **env)
{
	t_doom			*doom;

	doom = (t_doom*)ft_memalloc(sizeof(t_doom));
	if (!(doom->mlx = mlx_init()))
		ft_error("Failed to initalize the mlx");
	if (!(doom->window = mlx_new_window(doom->mlx, WIN_WIDTH,
	WIN_HEIGHT, "doom-nukem")))
		ft_error("MLX failed to create a window");
	mlx_clear_window(doom->mlx, doom->window);
	playerinit(doom);
	doom->param.sensitivity = 1.0;
	doom->param.mousepos = ft_vecdef(-6000, -6000, 0);
	mapinit(doom);
	imginit(doom);
	*env = doom;
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
	t_doom			*env;
	init(&env);
//	blueskintest();
	loop(env);
	return (0);
}
