/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:47:13 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/11 15:47:18 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

int			main(int argc, char **argv)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	if (argc >= 2)
	{
		e.stack_a = NULL;
		e.stack_b = NULL;
		e.count = argc - 1;
		check_args(&e, &argv[1]);
		if (read_instructions(&e) && e.size_b == 0)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		leave_program(-1, &e);
	}
	else
		leave_program(-1, &e);
	return (0);
}
