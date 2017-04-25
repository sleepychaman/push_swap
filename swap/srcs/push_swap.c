/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:28:38 by jgoncalv          #+#    #+#             */
/*   Updated: 2017/01/05 17:29:39 by jgoncalv         ###   ########.fr       */
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
