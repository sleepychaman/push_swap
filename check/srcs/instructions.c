/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:46:47 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/08 18:33:09 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

static void	exec_swap(t_env *e, char *directive)
{
	if (ft_strcmp(directive, "sa") == 0)
		swap_a(e);
	else if (ft_strcmp(directive, "sb") == 0)
		swap_b(e);
	else if (ft_strcmp(directive, "ss") == 0)
		swap_swap(e);
}

int			exec_instructions(t_env *e, char *directive)
{
	if (ft_strcmp(directive, "sa") == 0 || ft_strcmp(directive, "sb") == 0
			|| ft_strcmp(directive, "ss") == 0)
		exec_swap(e, directive);
	else if (ft_strcmp(directive, "pa") == 0)
		push_a(e);
	else if (ft_strcmp(directive, "pb") == 0)
		push_b(e);
	else if (ft_strcmp(directive, "ra") == 0)
		rotate_a(e);
	else if (ft_strcmp(directive, "rb") == 0)
		rotate_b(e);
	else if (ft_strcmp(directive, "rr") == 0)
		rotate_rotate(e);
	else if (ft_strcmp(directive, "rra") == 0)
		reverse_rotate_a(e);
	else if (ft_strcmp(directive, "rrb") == 0)
		reverse_rotate_b(e);
	else if (ft_strcmp(directive, "rrr") == 0)
		reverse_reverse_rotate(e);
	else
		return (1);
	return (0);
}

int			read_instructions(t_env *e)
{
	char *line;

	line = ft_strnew(BUFSIZ);
	while (get_next_line(STDIN, &line))
	{
		if (exec_instructions(e, line) == 1)
		{
			ft_bzero(line, BUFSIZ);
			free(line);
			leave_program(BAD_INSTRUCT, e);
		}
	}
	free(line);
	return (is_sort(e));
}
