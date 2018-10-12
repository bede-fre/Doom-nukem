/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:15:20 by bede-fre          #+#    #+#             */
/*   Updated: 2018/10/12 16:41:44 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		make_circular_lst(t_zone *zone)
{
	t_zone	*tmp_z;
	t_wall	*tmp_w;

	tmp_z = zone;
	while (tmp_z)
	{
		tmp_w = tmp_z->wall;
		while (tmp_w)
		{
			printf("%d;%d;%.0f;%.0f;%d\n", tmp_z->num, tmp_w->num, tmp_w->origin.x, tmp_w->origin.y, tmp_w->nextzone);
			tmp_w = tmp_w->next;
		}
		tmp_w = (t_wall*)ft_memalloc(sizeof(t_wall));
		tmp_w->next = tmp_z->wall;
		tmp_z = tmp_z->next;
	}
}

static void		free_infos(char **infos)
{
	int	i;

	i = -1;
	while (infos[++i])
		free(infos[i]);
	free(infos);
}

static t_zone	*search_zone(int num,  t_zone *zone)
{
	t_zone	*tmp_z;
	t_zone	*new_z;

	tmp_z = zone;
	while (tmp_z->num != num && tmp_z->next)
		tmp_z = tmp_z->next;
	if (tmp_z->num == num)
		return (tmp_z);
	else
	{
		new_z = (t_zone*)ft_memalloc(sizeof(t_zone));
		new_z->num = num;
		new_z->next = NULL;
		new_z->wall = NULL;
		tmp_z->next = new_z;
	}
	return (new_z);
}

static t_wall	*search_wall(int num,  t_wall *wall)
{
	t_wall	*tmp_w;
	t_wall	*new_w;

	tmp_w = wall;
	while (tmp_w->next && tmp_w->next->num < num)
		tmp_w = tmp_w->next;
	if (tmp_w->num < num)
	{
		new_w = (t_wall*)ft_memalloc(sizeof(t_wall));
		new_w->next = (tmp_w->next) ? tmp_w->next : NULL;
		tmp_w->next = new_w;
	}
	else
	{
		new_w = (t_wall*)ft_memalloc(sizeof(t_wall));
		new_w->next = (tmp_w) ? tmp_w : NULL;
		wall = new_w;
	}
	return (new_w);
}

static void		stock_wall(t_wall *wall, char **infos)
{
	wall->num = ft_atoi(infos[1]);
	wall->origin.x = ft_atoi(infos[2]);
	wall->origin.y = ft_atoi(infos[3]);
	wall->nextzone = ft_atoi(infos[4]);
	wall->next = NULL;
}

static void		mapinit(t_zone *zone)
{
	t_zone	*tmp_z;
	t_wall	*tmp_w;
	int		fd;
	char	*line;
	char	**infos;

	if ((fd = open("maps/map0", O_RDONLY)) == -1)
		exit(0);
	if (get_next_line(fd, &line) <= 0)
		exit(0);
	infos = ft_strsplit(line, ';');
	zone = (t_zone*)ft_memalloc(sizeof(t_zone));
	zone->num = ft_atoi(infos[0]);
	zone->next = NULL;
	zone->wall = (t_wall*)ft_memalloc(sizeof(t_wall));
	stock_wall(zone->wall, infos);
	free_infos(infos);
	while (get_next_line(fd, &line) > 0)
	{
		infos = ft_strsplit(line, ';');
		tmp_z = search_zone(ft_atoi(infos[0]), zone);
		if (!tmp_z->wall)
		{
			tmp_z->wall = (t_wall*)ft_memalloc(sizeof(t_wall));
			stock_wall(tmp_z->wall, infos);
		}
		else
		{
			tmp_w = search_wall(ft_atoi(infos[1]), tmp_z->wall);
			stock_wall(tmp_w, infos);
		}
		free_infos(infos);
	}
	make_circular_lst(zone);
}

static void		playerinit(t_doom *env)
{
	env->player.pos = ft_vecdef(10.0, 10.0, 0.0);
	env->player.rot = ft_vecdef(0.0, -1.0, 0.0);
	env->angle = ft_vec_angle(ft_vecdef(0.0, -1.0, 0.0), env->player.rot);
	env->player.rotangle = ft_vecdef(0.0, 0.0, -90.0);
	env->player.speed = 0.1;
}

static void		imginit(t_doom *env)
{
	img_get(&env->img, WIN_WIDTH, WIN_HEIGHT, env);
	img_get(&env->minimap, MAP_WIDTH, MAP_HEIGHT, env);
}

void			init(t_doom *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("Failed to initalize the mlx");
	if (!(env->window = mlx_new_window(env->mlx, WIN_WIDTH,
	WIN_HEIGHT, "doom-nukem")))
		ft_error("MLX failed to create a window");
	mlx_clear_window(env->mlx, env->window);
	playerinit(env);
	env->param.sensitivity = 0.3;
	env->param.mousepos = ft_vecdef(-6000.0, -6000.0, 0.0);
	mapinit(env->zone);
	mapimgalloc(env->zone, &env->map, env);
	imginit(env);
}
