/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:16:11 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/24 22:16:12 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	noodle(t_box **ba, t_box **bb, unsigned int len)
{
	t_com			*com;

	com = NULL;
	ft_getcom(&com);
	ft_execute(ba, bb, com);
	if (ft_checker(*ba, len) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	boxdel(ba);
	boxdel(bb);
	comdel(&com);
}

int					main(int ac, char **av)
{
	t_box			*ba;
	t_box			*bb;
	t_opt			opt;
	int				i;

	i = 1;
	ba = NULL;
	bb = NULL;
	opt.opt = nul;
	if (ac > 1)
	{
		if (ft_strcmp(av[i], "-c") == 0)
		{
			opt.opt = c;
			i++;
		}
		else if (ft_strcmp(av[i], "-v") == 0)
		{
			opt.opt = v;
			i++;
		}
		if (ac > i)
			noodle(&ba, &bb, ft_getnbr(av + i, ac - i, &ba));
	}
	return (0);
}
