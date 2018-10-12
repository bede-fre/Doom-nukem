/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:47:21 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/17 12:32:46 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*newlst;
	t_list		*current;

	if (lst == NULL)
		return (NULL);
	newlst = f(lst);
	current = newlst;
	lst = lst->next;
	while (lst)
	{
		current->next = f(lst);
		current = current->next;
		lst = lst->next;
	}
	current = NULL;
	return (newlst);
}
