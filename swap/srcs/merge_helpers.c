/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 23:39:37 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/15 03:22:13 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

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

void			set_len_vals(t_env *e, int *len, int y)
{
	len[1] = e->size_b - y - 1;
	len[4] = MAX(len[0], len[1]);
	if (len[0] + e->size_b - len[1] < len[4])
	{
		len[4] = len[0] + e->size_b - len[1];
		len[2] = 2;
	}
	if (e->size_a - len[0] + len[1] < len[4])
	{
		len[4] = e->size_a - len[0] + len[1];
		len[2] = 3;
	}
	if (MAX(e->size_a - len[0], e->size_b - len[1]) < len[4])
	{
		len[4] = MAX(e->size_a - len[0], e->size_b - len[1]);
		len[2] = 1;
		len[0] = e->size_a - len[0];
		len[1] = e->size_b - len[1];
	}
}

void			rotate_individuals(t_env *e, int *len)
{
	if (len[2] == 2)
	{
		while (len[0]-- > 0)
			ra(e);
		len[1] = e->size_b - len[1];
		while (len[1]-- > 0)
			rrb(e);
		return ;
	}
	len[0] = e->size_a - len[0];
	while (len[0]-- > 0)
		rra(e);
	while (len[1]-- > 0)
		rb(e);
	return ;
}

static void		setup_sort(int **best, int *len, t_env *e)
{
	*best = 0;
	*len = (e->size_a > 200) ? 57 : *len;
}

void			sort_big_a_on_b(t_env *e, int len, int x, int *tmp)
{
 	int *best;

	setup_sort(&best, &len, e);
	while (e->size_a > len && !(check_rotates(e)
		|| is_stack_sort(e->stack_a, e->size_a, 0)))
	{
		x = -1;
		while (++x < e->size_a)
		{
			if (best && x >= best[4] && e->size_a - best[4] - 1 > x)
				x = e->size_a - best[4] - 1;
			tmp = find_len(e, x);
			if (best == 0 || tmp[4] <= best[4])
			{
				if (best)
					free(best);
				best = tmp;
			}
			else
				free(tmp);
		}
		do_sort(e, best);
		free(best);
		best = 0;
	}
}
