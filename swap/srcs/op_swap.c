/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 17:42:32 by dcognata          #+#    #+#             */
/*   Updated: 2017/03/12 19:18:46 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	swap_a(t_env *e)
{
	int	tmp;

	if (e->size_a > 1)
	{
		tmp = e->stack_a->data;
		e->stack_a->data = e->stack_a->next->data;
		e->stack_a->next->data = tmp;
	}
	add_operation("sa\0");
	if (e->print == 1)
		view_list(e);
}

void	swap_b(t_env *e)
{
	int	tmp;

	if (e->size_b > 1)
	{
		tmp = e->stack_b->data;
		e->stack_b->data = e->stack_b->next->data;
		e->stack_b->next->data = tmp;
	}
	add_operation("sb\0");
	if (e->print == 1)
		view_list(e);
}

void	swap_swap(t_env *e)
{
	swap_a(e);
	swap_b(e);
	add_operation("ss\0");
	if (e->print == 1)
		view_list(e);
}
