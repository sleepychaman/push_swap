/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:43:48 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/08 14:30:53 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void		update_mid(t_env *e)
{
	e->middle = e->size_a / 2;
}

static void	get_min(t_env *e, t_link *tmp, int i)
{
	if (tmp->data < tmp->next->data
		&& tmp->data <= e->min && tmp->next != NULL)
	{
		e->min_pos = i;
		e->min = tmp->data;
	}
	else if (tmp->data > tmp->next->data
		&& tmp->next->data <= e->min && tmp->next != NULL)
	{
		e->min_pos = i + 1;
		e->min = tmp->next->data;
	}
}

void		search_min(t_env *e)
{
	t_link	*tmp;
	int		i;

	i = 1;
	e->min = A_FIRST;
	if (e->stack_a != NULL)
	{
		tmp = e->stack_a;
		while (tmp->next != NULL)
		{
			get_min(e, tmp, i);
			tmp = tmp->next;
			i++;
		}
	}
}
