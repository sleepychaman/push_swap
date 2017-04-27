/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:17:10 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/24 22:17:11 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	ft_rotate_rev_now(t_box **box)
{
	t_box *tmp;
	t_box *tmp2;

	tmp = *box;
	tmp2 = *box;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp->next = *box;
	*box = tmp;
	tmp2->next = NULL;
}

void				ft_rotate_rev(t_box **ba, t_box **bb, int pile)
{
	if ((pile == 1 || pile == 0) && *ba && (*ba)->next)
		ft_rotate_rev_now(ba);
	else if ((pile == 2 || pile == 0) && *bb && (*bb)->next)
		ft_rotate_rev_now(bb);
}
