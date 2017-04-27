/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:17:20 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/24 22:17:21 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	ft_swap_now(t_box **box)
{
	t_box	*tmp;

	tmp = *box;
	*box = (*box)->next;
	tmp->next = (*box)->next;
	(*box)->next = tmp;
}

void				ft_swap(t_box **ba, t_box **bb, int pile)
{
	if ((pile == 1 || pile == 0) && *ba && (*ba)->next)
		ft_swap_now(ba);
	if ((pile == 2 || pile == 0) && *bb && (*bb)->next)
		ft_swap_now(bb);
}
