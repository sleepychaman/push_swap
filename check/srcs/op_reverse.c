/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:47:40 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/11 15:47:41 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

void		reverse_rotate_a(t_env *e)
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
	}
}

void		reverse_rotate_b(t_env *e)
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
	}
}

void		reverse_reverse_rotate(t_env *e)
{
	if (e->size_a > 1 || e->size_b > 1)
	{
		if (e->size_a > 1)
			reverse_rotate_a(e);
		if (e->size_b > 1)
			reverse_rotate_b(e);
	}
}
