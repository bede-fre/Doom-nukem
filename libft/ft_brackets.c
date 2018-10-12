/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:48:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/08 14:54:03 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_point(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '(' && str[i] != '{' && str[i] != '['
		&& str[i] != ')' && str[i] != '}' && str[i] != ']' && str[i] != '\0')
			str[i] = '.';
		++i;
	}
}

static void	ft_cut(char *str)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (str[++i])
	{
		j = i;
		tmp = i;
		while (str[j] == '.')
			++j;
		while (str[j])
		{
			str[tmp] = str[j];
			++tmp;
			++j;
		}
		while (str[tmp])
		{
			str[tmp] = '\0';
			++tmp;
		}
	}
}

static int	ft_check(char *str)
{
	int	secu;
	int	i;

	secu = ft_strlen(str);
	while (secu > 0)
	{
		i = -1;
		while (str[++i])
		{
			if ((str[i] == '(' && str[i + 1] == ')')
			|| (str[i] == '{' && str[i + 1] == '}')
			|| (str[i] == '[' && str[i + 1] == ']'))
			{
				str[i] = '.';
				str[i + 1] = '.';
				ft_cut(str);
			}
		}
		--secu;
	}
	return (1);
}

int			ft_brackets(char *str)
{
	int		return_value;
	char	*cpy;

	if (!(cpy = ft_strdup(str)))
		return (-1);
	ft_point(cpy);
	ft_cut(cpy);
	ft_check(cpy);
	return_value = (cpy[0] != '\0') ? 0 : 1;
	ft_memdel((void **)&cpy);
	return (return_value);
}
