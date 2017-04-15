/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:43:05 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/17 13:43:05 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlist;
	t_list *start;

	if ((newlist = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	newlist = f(lst);
	start = newlist;
	while (lst->next)
	{
		if ((newlist->next = (t_list *)malloc(sizeof(t_list))) == NULL)
			return (NULL);
		lst = lst->next;
		newlist->next = f(lst);
		newlist = newlist->next;
	}
	return (start);
}
