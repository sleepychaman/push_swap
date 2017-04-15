/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:43:04 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/05 21:02:35 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void		move_to_a(t_env *e)
{
	e->op = e->op;
	while (e->size_b > 0)
		push_a(e);
}

void		check_special(t_env *e)
{
	if (A_FIRST > A_SECOND && A_LAST > A_FIRST)
		swap_a(e);
	else if (A_LAST < A_BLAST && A_LAST > A_FIRST)
	{
		reverse_a(e);
		reverse_a(e);
		swap_a(e);
		rotate_a(e);
		rotate_a(e);
	}
	else if (A_FIRST > A_SECOND && A_LAST < A_FIRST)
		rotate_a(e);
	else if (A_LAST < A_BLAST && A_LAST < A_FIRST)
		reverse_a(e);
}

void		normal_sort(t_env *e)
{
	check_special(e);
 	if (is_sort(e, A))
 		return ;
	special_sort(e);
	move_to_a(e);
}
