/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:48:25 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/11 15:48:26 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

static void	free_stack(t_env *e)
{
	t_link	*tmp;

	if (e->stack_a)
	{
		tmp = e->stack_a;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (tmp->prev)
				free(tmp->prev);
		}
		free(tmp);
	}
	if (e->stack_b)
	{
		tmp = e->stack_b;
		while (tmp->prev != NULL)
		{
			tmp = tmp->prev;
			e->stack_b->prev = NULL;
			if (tmp->next)
				free(tmp->next);
		}
		free(tmp);
	}
}

void		leave_program(int error, t_env *e)
{
	if (error == BAD_FORMAT || error == MISSING_STACK || error == DUPLICATE_STR
		|| error == BAD_ARGS || error == OVERFLOW || error == MALLOC_FAILED ||
		error == BAD_INSTRUCT)
		ft_putendl("\033[31mError\033[0m");
	free_stack(e);
	exit(1);
}
