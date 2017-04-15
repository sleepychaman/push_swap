/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:47:56 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/11 15:47:57 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

void		rotate_a(t_env *e)
{
	t_link	*last;
	t_link	*second;

	last = e->stack_a->prev;
	second = e->stack_a->next;
	if (e->size_a > 1)
	{
		last->next = e->stack_a;
		last->next->next = NULL;
		e->stack_a = second;
	}
}

void		rotate_b(t_env *e)
{
	t_link	*last;
	t_link	*second;

	last = e->stack_b->prev;
	second = e->stack_b->next;
	if (e->size_b > 1)
	{
		last->next = e->stack_b;
		last->next->next = NULL;
		e->stack_b = second;
	}
}

void		rotate_rotate(t_env *e)
{
	if (e->size_a > 1 || e->size_b > 1)
	{
		if (e->size_a > 1)
			rotate_a(e);
		if (e->size_b > 1)
			rotate_b(e);
	}
}
