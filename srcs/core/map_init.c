/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:27:10 by lguiller          #+#    #+#             */
/*   Updated: 2018/10/16 13:43:03 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void		free_infos(char **infos)
{
	int	i;

	i = -1;
	while (infos[++i])
		free(infos[i]);
	free(infos);
}

static void		stock_wall(t_wall *wall, char **infos)
{
	wall->num = ft_atoi(infos[1]);
	wall->origin.x = ft_atoi(infos[2]);
	wall->origin.y = ft_atoi(infos[3]);
	wall->nextzone = ft_atoi(infos[4]);
	wall->next = NULL;
}

static void		add_wall(char **infos, t_wall *wall)
{
	while (wall->next)
		wall = wall->next;
	wall->next = (t_wall*)ft_memalloc(sizeof(t_wall));
	stock_wall(wall->next, infos);
}

static void		search_zone(char **infos, t_zone *zone)
{
	int		num;

	num = ft_atoi(infos[0]);
	while (zone->num != num && zone->next)
		zone = zone->next;
	if (zone->num == num)
		add_wall(infos, zone->wall);
	else
	{
		zone->next = (t_zone*)ft_memalloc(sizeof(t_zone));
		zone = zone->next;
		zone->num = num;
		zone->next = NULL;
		zone->wall = (t_wall*)ft_memalloc(sizeof(t_wall));
		stock_wall(zone->wall, infos);
	}
}

void			mapinit(t_doom *env)
{
	t_zone	*tmp_z;
	int		fd;
	char	*line;
	char	**infos;

	if ((fd = open("maps/map0", O_RDONLY)) == -1 ||
			get_next_line(fd, &line) <= 0)
		exit(0);
	infos = ft_strsplit(line, ';');
	env->zone = (t_zone*)ft_memalloc(sizeof(t_zone));
	env->zone->num = ft_atoi(infos[0]);
	env->zone->next = NULL;
	env->zone->wall = (t_wall*)ft_memalloc(sizeof(t_wall));
	stock_wall(env->zone->wall, infos);
	free_infos(infos);
	while (get_next_line(fd, &line) > 0)
	{
		tmp_z = env->zone;
		infos = ft_strsplit(line, ';');
		search_zone(infos, tmp_z);
		free_infos(infos);
	}
	sort_list(env->zone);
	make_circular_lst(env->zone);
}
