/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmace <cmace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:12:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/27 10:46:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

void	init_xpm(t_mlx ptr, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(ptr.mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_error("error", 11, perror);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->endian);
}

void	display_map(char map[MAPY][MAPX])
{
	int i;
	int j;

	i = 0;
	while (i < MAPY)
	{
		j = 0;
		while (j < MAPX)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
