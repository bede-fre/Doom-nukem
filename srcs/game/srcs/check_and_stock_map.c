/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_stock_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:40:30 by bede-fre          #+#    #+#             */
/*   Updated: 2018/12/07 11:07:46 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

static void	ft_check_start(char *buff, int *start, int *tp, int *jetpack)
{
	int i;

	i = -1;
	while (++i < BUFF_SIZE)
	{
		if (buff[i] == START)
			++(*start);
		if (*start > 1)
			ft_error("error: More than one departure area", 2, ft_puterror);
		if (buff[i] == TP_E)
			++(*tp);
		if (*tp > 1)
			ft_error("error: More than one exit teleportation", 3, ft_puterror);
		if (buff[i] == JETPACK)
			++(*jetpack);
		if (*jetpack > 1)
			ft_error("error: More than one jetpack", 4, ft_puterror);
	}
}

static void	ft_check_char(char *buff)
{
	int i;

	i = -1;
	while (++i < BUFF_SIZE)
		if (buff[i] != FLOOR && buff[i] != START && buff[i] != TP_S
			&& buff[i] != TP_E && !is_displayable(buff[i]) && buff[i] != DOOR_O
			&& buff[i] != DOOR_C && buff[i] != END && !is_sprite(buff[i]))
			ft_error("error: Wrong character found", 4, ft_puterror);
}

static void	ft_check_map(char *buff, int *start, int *tp, int *jetpack)
{
	if (ft_strlen(buff) != BUFF_SIZE)
		ft_error("error: Wrong line length", 1, ft_puterror);
	ft_check_start(buff, start, tp, jetpack);
	ft_check_char(buff);
}

static void	ft_other_test(int test_gnl, int i, int start)
{
	if (test_gnl == -1)
		ft_error("error: Not valid file", 7, ft_puterror);
	if (i < BUFF_SIZE)
		ft_error("error: Wrong column lenght", 8, ft_puterror);
	if (start == 0)
		ft_error("error: No start found", 9, ft_puterror);
}

void		ft_read_file(char *name, char (*map)[MAPY][MAPX])
{
	t_parse		parse;
	int			start;
	int			tp;
	int			jetpack;
	int			test_gnl;

	start = 0;
	tp = 0;
	jetpack = 0;
	if ((parse.fd = open(name, O_RDONLY)) == -1)
		ft_error("error", 5, perror);
	parse.i = 0;
	while ((test_gnl = get_next_line(parse.fd, &parse.buff)) > 0)
	{
		if (++parse.i > BUFF_SIZE)
			ft_error("error: Wrong column length", 6, ft_puterror);
		ft_check_map(parse.buff, &start, &tp, &jetpack);
		ft_strcpy(map[0][parse.i - 1], parse.buff);
		ft_memdel((void **)&parse.buff);
	}
	ft_memdel((void **)&parse.buff);
	ft_other_test(test_gnl, parse.i, start);
	if ((close(parse.fd)) == -1)
		ft_error("error", 10, perror);
}
