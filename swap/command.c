/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:17:42 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/24 22:17:43 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_getpile(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0')
			c = str[i];
		i++;
	}
	if (c == 'a')
		return (1);
	else if (c == 'b')
		return (2);
	else
		return (0);
}

unsigned int	ft_count_nbr(t_box *box)
{
	unsigned int	len;

	len = 0;
	while (box)
	{
		len++;
		box = box->next;
	}
	return (len);
}

void			ft_execute(t_box **ba, t_box **bb, t_com *com)
{
	while (com)
	{
		if (com->com == s)
			ft_swap(ba, bb, com->pile);
		else if (com->com == p)
			ft_push(ba, bb, com->pile);
		else if (com->com == r)
			ft_rotate(ba, bb, com->pile);
		else if (com->com == rr)
			ft_rotate_rev(ba, bb, com->pile);
		com = com->next;
	}
}
