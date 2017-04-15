/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:47:28 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/08 19:15:41 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/checker.h"

static void	add_link_head_b(t_env *e, int val)
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
		e->stack_b = new;
		new->next = tmp;
		tmp->prev = e->stack_b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
	}
	else
	{
		e->stack_b = new;
	}
	e->size_b++;
}

static void	add_link_head_a(t_env *e, int val)
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
		e->stack_a = new;
		new->next = tmp;
		tmp->prev = e->stack_a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
	}
	else
	{
		e->stack_a = new;
	}
	e->size_a++;
}

void		push_a(t_env *e)
{
	if (e->size_b > 0 && e->stack_b != NULL)
	{
		add_link_head_a(e, e->stack_b->data);
		remove_link_b(e);
	}
}

void		push_b(t_env *e)
{
	if (e->size_a > 0 && e->stack_a != NULL)
	{
		add_link_head_b(e, e->stack_a->data);
		remove_link_a(e);
	}
}
