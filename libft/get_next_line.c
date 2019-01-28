/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:24:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:58:12 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_check(t_list **list, size_t fd)
{
	t_list	*current;
	t_list	*elem;

	current = *list;
	while (current)
	{
		if (current->content_size == fd)
			return (current);
		current = current->next;
	}
	elem = (t_list *)ft_memalloc(sizeof(t_list));
	elem->content = ft_memalloc(sizeof(t_struct));
	elem->content_size = fd;
	ft_lstadd(list, elem);
	return (elem);
}

static char		ft_getchar(t_list *link, int *rd_len)
{
	t_struct	*var;
	size_t		fd;
	char		c;

	fd = link->content_size;
	var = ((t_struct *)link->content);
	if (var->len == 0)
	{
		if ((*rd_len = read(fd, var->buff, BUFF_SIZE)) <= 0)
			return ((*rd_len == 0) ? 0 : -1);
		var->len = *rd_len;
		var->str = (char *)&var->buff;
	}
	c = *var->str;
	++var->str;
	--var->len;
	return (c);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*link;
	char			c;
	int				len;

	if (line == NULL || fd < 0 || !BUFF_SIZE || !(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	link = (t_list *)ft_check(&list, (size_t)fd);
	c = ft_getchar(link, &(((t_struct *)link->content)->rd_len));
	if (((t_struct *)link->content)->rd_len < 0)
		return (-1);
	len = 0;
	while (c != GNL_CAR && (((t_struct *)link->content))->rd_len > 0)
	{
		line[0][len] = c;
		c = ft_getchar(link, &(((t_struct *)link->content)->rd_len));
		++len;
		if ((len % BUFF_SIZE) == 0)
			*line = ft_realloc(*line, len + BUFF_SIZE + 1);
	}
	line[0][len] = '\0';
	return ((**line == '\0' && c != GNL_CAR) ? 0 : 1);
}
