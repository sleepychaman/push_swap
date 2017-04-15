/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:41:33 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/12 21:43:35 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static void	put_rules(t_env *e, char *stack)
{
	check_args(e, &stack);
	ft_putstr("Usage: push_swap [-v] [-help] ... Stack In\n");
	leave_program(BAD_ARGS, e);
}

int			main(int argc, char **argv)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	if (argc >= 2)
	{
		e.stack_a = NULL;
		e.stack_b = NULL;
		e.count = argc - 1;
		if (ft_isnumeric(argv[1]) == 0 && (ft_strcmp(argv[1], "-v") == 0))
		{
			e.print = 1;
			if (argc == 2)
				leave_program(MISSING_STACK, &e);
			check_args(&e, &argv[2]);
		}
		else if (ft_isnumeric(argv[1]) == 0
			&& (ft_strncmp(argv[1], "-", 1) == 0))
			put_rules(&e, argv[1]);
		else
			check_args(&e, &argv[1]);
	}
	else
		put_rules(&e, argv[1]);
	return (0);
}
