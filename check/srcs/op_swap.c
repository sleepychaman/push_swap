/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:48:14 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/11 15:48:15 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

void	swap_a(t_env *e)
{
	int	tmp;

	if (e->size_a > 1)
	{
		tmp = e->stack_a->data;
		e->stack_a->data = e->stack_a->next->data;
		e->stack_a->next->data = tmp;
	}
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
}

void	swap_swap(t_env *e)
{
	swap_a(e);
	swap_b(e);
}
