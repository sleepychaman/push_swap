/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:41:08 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/20 20:41:54 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void		check_duplicate(t_env *e, char **list)
{
	CNT		i;
	CNT		j;
	char	*arg;

	i = 0;
	j = 0;
	while (list[i] != NULL)
	{
		arg = list[i];
		while (list[j] != NULL)
		{
			if (j != i)
				if (ft_strcmp(arg, list[j]) == 0)
					leave_program(DUPLICATE_STR, e);
			j++;
		}
		j = 0;
		i++;
	}
}

static char	**parse_text(t_env *e, char *stack, int *j)
{
	char	**clean_stack;
	int		i;

	i = 0;
	clean_stack = ft_strsplit(stack, ' ');
	while (clean_stack[i] != NULL)
		i++;
	e->count = i;
	check_duplicate(e, clean_stack);
	j--;
	return (clean_stack);
}

void		free_args(char **args)
{
	int		j;

	j = 0;
	while (args[j] != NULL)
	{
		free(args[j]);
		j++;
	}
	free(args);
}

void		check_args(t_env *e, char **args)
{
	long	tmp;
	int		i;
	int		j;

	j = 1;
	i = 0;
	e->count = (e->print == 1) ? e->count - 1 : e->count;
	if (e->count != 1)
		check_duplicate(e, args);
	else
		args = parse_text(e, args[0], &j);
	while (i < e->count)
	{
		if (ft_isnumeric(args[i]) == 0)
			leave_program(BAD_FORMAT, e);
		tmp = ft_atoi(args[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			leave_program(OVERFLOW, e);
		add_link_a(e, (int)tmp);
		i++;
	}
	if (j == 0)
		free_args(args);
	push_swap(e);
	leave_program(-1, e);
}
