/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:16:50 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/24 22:16:51 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	ft_push_now(t_box **b1, t_box **b2)
{
	t_box *tmp;

	tmp = *b1;
	*b1 = (*b1)->next;
	tmp->next = *b2;
	*b2 = tmp;
}

void				ft_push(t_box **ba, t_box **bb, int pile)
{
	if (pile == 1 && *bb != NULL)
		ft_push_now(bb, ba);
	else if (pile == 2 && *ba != NULL)
		ft_push_now(ba, bb);
}
