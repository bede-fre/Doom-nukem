/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:57:32 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/09 21:01:00 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	write_file(char *file_name, char map[MAP_HEIGHT][MAP_WIDTH])
{
	int		fd;
	t_point	i;

	if ((fd = open(file_name, O_WRONLY)) == -1)
		ft_error("error", 11, perror);
	i.y = -1;
	while (++i.y < MAP_HEIGHT)
	{
		i.x = -1;
		while (++i.x < MAP_WIDTH)
			ft_putchar_fd(map[i.y][i.x], fd);
		ft_putchar_fd('\n', fd);
	}
	if (close(fd) == -1)
		ft_error("error", 12, perror);
}
