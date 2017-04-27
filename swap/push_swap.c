/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:18:39 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/25 00:51:35 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_tri(t_box *box)
{
	t_box			*tmp;
	t_box			*tmptmp;
	unsigned int	i;

	tmptmp = box;
	while (box)
	{
		i = 0;
		tmp = tmptmp;
		while (tmp)
		{
			if (tmp->nbr < box->nbr)
				i++;
			tmp = tmp->next;
		}
		box->i = i;
		box = box->next;
	}
}

int			main(int ac, char **av)
{
	t_box			*ba;
	t_box			*bb;
	unsigned int	len;

	ba = NULL;
	bb = NULL;
	if (ac > 1)
	{
		len = ft_getnbr(av + 1, ac - 1, &ba);
		ft_tri(ba);
		if (ft_checker(ba, len) != 1)
			start(&ba, &bb);
		boxdel(&ba);
		boxdel(&bb);
	}
	return (0);
}
