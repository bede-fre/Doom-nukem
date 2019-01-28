/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:16:40 by lguiller          #+#    #+#             */
/*   Updated: 2018/11/28 09:57:38 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_nb(const char *nb, int base)
{
	int		i;
	int		j;
	char	*tab;

	tab = "0123456789abcdef";
	i = (nb[0] == '0' && nb[1] == 'x' && base == 16) ? 1 : -1;
	while (nb[++i])
	{
		j = 0;
		while (j < base && nb[i] != tab[j])
			++j;
		if (j == base && nb[i] != tab[i])
			return (0);
	}
	return (1);
}

int			ft_atoi_base(const char *str, int base)
{
	int		value;
	int		nb_len;
	int		i;
	int		stop;
	char	*tmp;

	tmp = ft_lowercase(str);
	if (base == 10)
		return (ft_atoi(tmp));
	if (tmp == NULL || base < 2 || base > 16 || !ft_check_nb(tmp, base))
		return (0);
	nb_len = ft_strlen(tmp) - 1;
	value = 0;
	i = 0;
	stop = (tmp[0] == '0' && tmp[1] == 'x' && base == 16) ? 2 : 0;
	while (nb_len >= stop)
	{
		if (tmp[nb_len] >= 'a' && tmp[nb_len] <= 'z')
			value += (((tmp[nb_len--] - 'a') + 10) * ft_pow(base, i++));
		if (tmp[nb_len] >= '0' && tmp[nb_len] <= '9')
			value += ((tmp[nb_len--] - '0') * ft_pow(base, i++));
	}
	ft_memdel((void**)(&tmp));
	return (value);
}
