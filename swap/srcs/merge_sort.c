/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 03:00:32 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/15 05:13:06 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int		*find_len(t_env *e, int x)
{
	int *len;
	int cmp[2];
	int y;
	int found;

	len = ft_memalloc(sizeof(int) * 5);
	if (e->size_b < 2)
		return (len);
	while (x-- && e->stack_a->next)
		e->stack_a = e->stack_a->next;
	x = y;
	while (x-- && e->stack_b->next)
		e->stack_b = e->stack_b->next;
	len[0] = e->size_a - x - 1;
	y = e->size_b;
	found = 0;
	while (!found && --y >= 0 && e->stack_b->prev)
	{
		cmp[0] = e->stack_b->data;
		cmp[1] = (y == e->size_b - 1) ? B_FIRST : e->stack_b->next->data;
		if (cmp[0] < e->stack_a->data && cmp[1] > e->stack_a->data)
			found = 1;
		else if (cmp[0] < e->stack_a->data && (cmp[1] == find_min(e->stack_b, e->size_b)))
			found = 1;
		else if (cmp[1] > e->stack_a->data && (cmp[0] == find_max(e->stack_b, e->size_b)))
			found = 1;
		e->stack_b = e->stack_b->prev;
	}
	set_len_vals(e, len, y);
	return (len);
}

void	do_sort(t_env *e, int *len)
{
	if (len[2] > 1)
	{
		rotate_individuals(e, len);
		return ;
	}
	while (len[0] > 0 && len[1] > 0)
	{
		len[2] ? rrr(e, 1) : rr(e, 1);
		len[0]--;
		len[1]--;
	}
	while (len[0]-- > 0)
		len[2] ? rra(e, 1) : ra(e, 1);
	while (len[1]-- > 0)
		len[2] ? rrb(e, 1) : rb(e, 1);
	pb(e);
}

void	sort_a_on_b(t_env *e, int len)
{
	int		i_min;
	int		count;

	i_min = 0;
	count = 0;
	while (e->size_a > len && !is_stack_sort(e->stack_a, e->size_a, 0))
	{
		i_min = find_min_i(e->stack_a, e->size_a);
		if (i_min == 0)
		{
			pb(e);
			count++;
		}
		else if (i_min <= e->size_a / 2)
			ra(e);
		else if (i_min > e->size_a / 2)
			rra(e);
	}
}

void	merge_b_to_a(t_env *e)
{
	while (e->size_b)
	{
		if (B_LAST < A_LAST && B_LAST > A_FIRST)
			pa(e);
		else if (B_LAST < A_LAST && A_FIRST == search_max(e))
			pa(e);
		else if (B_LAST > A_FIRST && A_LAST == search_min(e))
			pa(e);
		else
		{
			if (find_pos(e->stack_a, e->size_a, B_LAST) > e->size_a / 2)
				ra(e);
			else
				rra(e);
		}
	}
}

void	merge_sort(t_env *e)
{
	int x;

	sort_big_a_on_b(e, 2, 0, 0);
	sort_a_on_b(e, 2);
	merge_b_to_a(e);
	x = find_max_i(e->stack_a, e->size_a) + 1;
	if (x < e->size_a / 2)
		while (x--)
			ra(e);
	else
		while (x++ < e->size_a)
			rra(e);
 }
