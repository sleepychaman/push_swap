/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 00:12:07 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/28 10:17:49 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*find_len(t_ps *ps, int x)
{
	int *len;
	int cmp[2];
	int y;
	int found;

	len = ft_memalloc(sizeof(int) * 5);
	if (ps->b_len < 2)
		return (len);
	len[0] = ps->a_len - x - 1;
	y = ps->b_len;
	found = 0;
	while (!found && --y >= 0)
	{
		cmp[0] = ps->b[y];
		cmp[1] = (y == ps->b_len - 1) ? ps->b[0] : ps->b[y + 1];
		if (cmp[0] < ps->a[x] && cmp[1] > ps->a[x])
			found = 1;
		else if (cmp[0] < ps->a[x] && (cmp[1] == find_min(ps->b, ps->b_len)))
			found = 1;
		else if (cmp[1] > ps->a[x] && (cmp[0] == find_max(ps->b, ps->b_len)))
			found = 1;
	}
	set_len_vals(ps, len, y);
	return (len);
}

void	do_sort(t_ps *ps, int *len)
{
	if (len[2] > 1)
	{
		rotate_individuals(ps, len);
		return ;
	}
	while (len[0] > 0 && len[1] > 0)
	{
		len[2] ? rrr(ps, 1) : rr(ps, 1);
		len[0]--;
		len[1]--;
	}
	while (len[0]-- > 0)
		len[2] ? rra(ps, 1) : ra(ps, 1);
	while (len[1]-- > 0)
		len[2] ? rrb(ps, 1) : rb(ps, 1);
	pb(ps, 1);
}

void	sort_a_on_b(t_ps *ps, int len)
{
	int		i_min;
	int		count;

	i_min = 0;
	count = 0;
	while (ps->a_len > len && !is_stack_sort(ps->a, ps->a_len, 0))
	{
		i_min = find_min_i(ps->a, ps->a_len);
		if (i_min == 0)
		{
			pb(ps, 1);
			count++;
		}
		else if (i_min <= ps->a_len / 2)
			ra(ps, 1);
		else if (i_min > ps->a_len / 2)
			rra(ps, 1);
	}
}

void	merge_b_to_a(t_ps *ps)
{
	while (ps->b_len)
	{
		if (ps->b[ps->b_len - 1] < ps->a[ps->a_len - 1]
				&& ps->b[ps->b_len - 1] > ps->a[0])
			pa(ps, 1);
		else if (ps->b[ps->b_len - 1] < ps->a[ps->a_len - 1]
				&& ps->a[0] == find_max(ps->a, ps->a_len))
			pa(ps, 1);
		else if (ps->b[ps->b_len - 1] > ps->a[0]
				&& ps->a[ps->a_len - 1] == find_min(ps->a, ps->a_len))
			pa(ps, 1);
		else
		{
			if (find_pos(ps->a, ps->a_len, ps->b[ps->b_len - 1])
				> ps->a_len / 2)
				ra(ps, 1);
			else
				rra(ps, 1);
		}
	}
}

void	merge_sort(t_ps *ps)
{
	int x;

	sort_big_a_on_b(ps, 2, 0, 0);
	sort_a_on_b(ps, 2);
	merge_b_to_a(ps);
	x = find_max_i(ps->a, ps->a_len) + 1;
	if (x < ps->a_len / 2)
		while (x--)
			ra(ps, 1);
	else
		while (x++ < ps->a_len)
			rra(ps, 1);
}
