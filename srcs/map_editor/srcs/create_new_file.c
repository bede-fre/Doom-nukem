/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:45:18 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/19 11:52:53 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

void	create_new_file(char *file)
{
	int	fd;
	int	i;

	if ((fd = open(file, O_CREAT | O_EXCL | O_WRONLY,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		ft_error("error", 13, perror);
	ft_putstr_fd("s                               \n", fd);
	i = 0;
	while (++i < MAP_HEIGHT - 1)
		ft_putstr_fd("                                \n", fd);
	ft_putstr_fd("                                ", fd);
	if ((close(fd)) == -1)
		ft_error("error", 14, perror);
}
