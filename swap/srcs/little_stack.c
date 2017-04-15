/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:41:42 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/08 14:08:34 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	less_than_four(t_env *e)
{
	if (e->size_a == 2)
		if (e->stack_a->data > e->stack_a->next->data)
			swap_a(e);
	if (A_FIRST < A_SECOND && A_FIRST < A_LAST && A_SECOND > A_LAST)
	{
		rotate_a(e);
		swap_a(e);
		reverse_a(e);
	}
	else if (A_FIRST > A_LAST && A_SECOND < A_LAST)
		rotate_a(e);
	else if (A_FIRST > A_SECOND && A_SECOND < A_LAST)
		swap_a(e);
	else if (A_FIRST < A_SECOND && A_SECOND > A_LAST)
		reverse_a(e);
	else if (A_FIRST > A_SECOND && A_SECOND > A_LAST)
	{
		rotate_a(e);
		swap_a(e);
	}
}

static void	less_than_six(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (e->size_a > 3)
	{
		search_min(e);
		if (e->min_pos > e->size_a / 2)
		{
			j = e->min_pos;
			while (j <= e->size_a)
			{
				j++;
				reverse_a(e);
			}
		}
		else
			while (j < e->min_pos - 1)
			{
				j++;
				rotate_a(e);
			}
		j = 0;
		push_b(e);
		if (A_FIRST > A_SECOND)
			swap_a(e);
		i++;
	}
	less_than_four(e);
}

void		special_sort(t_env *e)
{
	if (e->size_a == 2)
	{
		if (e->stack_a->data > e->stack_a->next->data)
			swap_a(e);
	}
	else if (e->size_a == 3)
		less_than_four(e);
	else
		less_than_six(e);
}
