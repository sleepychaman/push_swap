/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 22:17:35 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/24 22:17:36 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdig(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		i++;
	}
	return (1);
}

static int	ft_is_int(char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	if (nbr < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	else if (nbr > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		exit(-1);
	}
	return (nbr);
}

int			check_nbr(t_box *box, int small, int big)
{
	int	i;

	i = 0;
	while (box)
	{
		if (box->nbr >= small && box->nbr <= big)
			i++;
		box = box->next;
	}
	return (i);
}

int			ft_checknbr(char *str, t_box *box)
{
	int	nbr;

	nbr = 0;
	ft_isdig(str);
	nbr = ft_is_int(str);
	while (box)
	{
		if (box->nbr == nbr)
		{
			ft_putstr_fd("Error\n", 2);
			exit(-1);
		}
		box = box->next;
	}
	return (nbr);
}

char		*ft_checkcom(char *str)
{
	if (ft_strcmp("sa", str) != 0 &&
	ft_strcmp("sb", str) != 0 &&
	ft_strcmp("ss", str) != 0 &&
	ft_strcmp("ra", str) != 0 &&
	ft_strcmp("rb", str) != 0 &&
	ft_strcmp("rr", str) != 0 &&
	ft_strcmp("rrr", str) != 0 &&
	ft_strcmp("rra", str) != 0 &&
	ft_strcmp("rrb", str) != 0 &&
	ft_strcmp("pb", str) != 0 &&
	ft_strcmp("pa", str) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (str);
}
