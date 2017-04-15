/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:40:46 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/11 15:41:18 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void		add_link_a(t_env *e, int val)
{
	t_link	*tmp;
	t_link	*new;

	tmp = e->stack_a;
	new = NULL;
	if ((new = (t_link *)malloc(sizeof(t_link))) == NULL)
		leave_program(MALLOC_FAILED, e);
	new->next = NULL;
	new->prev = NULL;
	new->data = val;
	if (e->stack_a != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		e->stack_a->prev = new;
		new->prev = tmp;
	}
	else
		e->stack_a = new;
	e->size_a++;
	update_mid(e);
}

void		add_link_b(t_env *e, int val)
{
	t_link	*tmp;
	t_link	*new;

	tmp = e->stack_b;
	new = NULL;
	if ((new = (t_link *)malloc(sizeof(t_link))) == NULL)
		leave_program(MALLOC_FAILED, e);
	new->next = NULL;
	new->prev = NULL;
	new->data = val;
	if (e->stack_b != NULL)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		e->stack_b->prev = new;
		new->prev = tmp;
	}
	else
		e->stack_b = new;
	e->size_b++;
}

void		remove_link_a(t_env *e)
{
	t_link	*tmp;
	t_link	*last;
	t_link	*fresh;

	if (e->size_a <= 1)
	{
		free(e->stack_a);
		e->stack_a = NULL;
	}
	else
	{
		if (e->stack_a != NULL)
		{
			tmp = e->stack_a->next;
			last = e->stack_a->prev;
			fresh = e->stack_a;
			e->stack_a = tmp;
			e->stack_a->prev = last;
			free(fresh);
		}
	}
	e->size_a--;
	update_mid(e);
}

void		remove_link_b(t_env *e)
{
	t_link	*tmp;
	t_link	*last;
	t_link	*fresh;

	if (e->size_b <= 1)
	{
		free(e->stack_b);
		e->stack_b = NULL;
	}
	else
	{
		if (e->stack_b != NULL)
		{
			tmp = e->stack_b->next;
			last = e->stack_b->prev;
			fresh = e->stack_b;
			e->stack_b = tmp;
			e->stack_b->prev = last;
			free(fresh);
		}
	}
	e->size_b--;
}

void		view_list(t_env *e)
{
	t_link	*tmp;

	tmp = e->stack_a;
	ft_putstr("\033[34;01m-------- PUSH_SWAP --------\033[00m\nstack_a : ");
	while (tmp != NULL)
	{
		ft_putnbr(tmp->data);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putstr("\nstack_b : ");
	tmp = e->stack_b;
	while (tmp != NULL)
	{
		ft_putnbr(tmp->data);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putstr("\n\033[34;01m---------------------------\033[00m\n");
}
