/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamon <aamon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:34:20 by dcognata          #+#    #+#             */
/*   Updated: 2017/04/05 20:34:33 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	push_swap(t_env *e)
{
	if (is_sort(e, A) == 0)
	{
		if (e->print == 1)
			view_list(e);
		if (e->size_a <= 3)
			special_sort(e);
		else
			normal_sort(e);
	}
	else
	{
		if (e->print == 1)
		{
			view_list(e);
			ft_putstr("Stack already sorted !\n");
		}
	}
}
