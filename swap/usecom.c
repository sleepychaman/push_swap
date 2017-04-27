/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usecom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:20:19 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/24 22:20:22 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usecom(t_box **ba, t_box **bb, char *str, int i)
{
	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rb\n")
		|| !ft_strcmp(str, "rr\n"))
	{
		ft_putstr(str);
		ft_rotate(ba, bb, i);
	}
	else if (!ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rrb\n")
		|| !ft_strcmp(str, "rrr\n"))
	{
		ft_putstr(str);
		ft_rotate_rev(ba, bb, i);
	}
	else if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "sb\n")
		|| !ft_strcmp(str, "ss\n"))
	{
		ft_putstr(str);
		ft_swap(ba, bb, i);
	}
	else if (!ft_strcmp(str, "pa\n") || !ft_strcmp(str, "pb\n"))
	{
		ft_putstr(str);
		ft_push(ba, bb, i);
	}
}
