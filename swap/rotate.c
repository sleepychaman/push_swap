/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:19:29 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/24 22:19:30 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	inline	void	ft_rotate_now(t_box **box)
{
	t_box *tmp;

	tmp = *box;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *box;
	tmp = *box;
	*box = (*box)->next;
	tmp->next = NULL;
}

void					ft_rotate(t_box **ba, t_box **bb, int pile)
{
	if ((pile == 1 || pile == 0) && *ba && (*ba)->next)
		ft_rotate_now(ba);
	if ((pile == 2 || pile == 0) && *bb && (*bb)->next)
		ft_rotate_now(bb);
}
