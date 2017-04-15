/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:42:43 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/08 19:03:15 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void		reverse_a(t_env *e)
{
	t_link	*last;
	t_link	*first;

	last = e->stack_a;
	first = e->stack_a;
	if (e->size_a > 1)
	{
		last = e->stack_a->prev;
		last->prev->next = NULL;
		e->stack_a->prev = last;
		e->stack_a = last;
		last->next = first;
		last->prev = last->prev;
		if (e->pront % 10 == 0 && e->size_a > 30)
		{
			add_operation("rra\0");
			if (e->print == 1)
				view_list(e);
		}
		else if (e->size_a <= 30)
		{
			add_operation("rra\0");
			if (e->print == 1)
				view_list(e);
		}
	}
}

void		reverse_b(t_env *e)
{
	t_link	*last;
	t_link	*first;

	last = e->stack_b;
	first = e->stack_b;
	if (e->size_b > 1)
	{
		last = e->stack_b->prev;
		last->prev->next = NULL;
		e->stack_b->prev = last;
		e->stack_b = last;
		last->next = first;
		last->prev = last->prev;
		add_operation("rra\0");
		if (e->print == 1)
			view_list(e);
	}
}

void		reverse_reverse(t_env *e)
{
	if (e->size_a > 1 || e->size_b > 1)
	{
		if (e->size_a > 1)
			reverse_a(e);
		if (e->size_b > 1)
			reverse_b(e);
		add_operation("rrr\0");
		if (e->print == 1)
			view_list(e);
	}
}










