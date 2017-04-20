/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 11:12:47 by mhurd             #+#    #+#             */
/*   Updated: 2016/12/29 22:58:34 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	len[0]: pos in stack a
**	len[1]: pos in stack b
**	len[2]: type of movement to do
**		0: rr
**		1: rrr
**		2: ra, rrb
**		3: rra, rb
**	len[3]: unused (whoops)
**	len[4]: Total moves
*/

void			set_len_vals(t_ps *ps, int *len, int y)
{
	len[1] = ps->b_len - y - 1;
	len[4] = MAX(len[0], len[1]);
	if (len[0] + ps->b_len - len[1] < len[4])
	{
		len[4] = len[0] + ps->b_len - len[1];
		len[2] = 2;
	}
	if (ps->a_len - len[0] + len[1] < len[4])
	{
		len[4] = ps->a_len - len[0] + len[1];
		len[2] = 3;
	}
	if (MAX(ps->a_len - len[0], ps->b_len - len[1]) < len[4])
	{
		len[4] = MAX(ps->a_len - len[0], ps->b_len - len[1]);
		len[2] = 1;
		len[0] = ps->a_len - len[0];
		len[1] = ps->b_len - len[1];
	}
}

void			rotate_individuals(t_ps *ps, int *len)
{
	if (len[2] == 2)
	{
		while (len[0]-- > 0)
			ra(ps, 1);
		len[1] = ps->b_len - len[1];
		while (len[1]-- > 0)
			rrb(ps, 1);
		return ;
	}
	len[0] = ps->a_len - len[0];
	while (len[0]-- > 0)
		rra(ps, 1);
	while (len[1]-- > 0)
		rb(ps, 1);
	return ;
}

static void		setup_sort(int **best, int *len, t_ps *ps)
{
	*best = 0;
	*len = (ps->a_len > 200) ? 57 : *len;
}

void			sort_big_a_on_b(t_ps *ps, int len, int x, int *tmp)
{
	int *best;

	setup_sort(&best, &len, ps);
	while (ps->a_len > len && !(check_rotates(ps)
		|| is_stack_sort(ps->a, ps->a_len, 0)))
	{
		x = -1;
		while (++x < ps->a_len)
		{
			if (best && x >= best[4] && ps->a_len - best[4] - 1 > x)
				x = ps->a_len - best[4] - 1;
			tmp = find_len(ps, x);
			if (best == 0 || tmp[4] <= best[4])
			{
				if (best)
					free(best);
				best = tmp;
			}
			else
				free(tmp);
		}
		do_sort(ps, best);
		free(best);
		best = 0;
	}
}
