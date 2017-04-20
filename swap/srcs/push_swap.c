/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamon <aamon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:34:20 by dcognata          #+#    #+#             */
/*   Updated: 2017/04/05 20:34:33 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int		*list_to_tab(t_env *e)
{
  int		*dec;
  int		i;

  if ((e->tab = (intmax_t*)malloc(sizeof(intmax_t) * (e->size_a + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < e->size_a)
    {
      e->tab[i] = e->stack_a->data;
      i++;
      e->stack_a = e->stack_a->next;
    }
  e->tab[i] = 214748364;
}

void	push_swap(t_env *e)
{
	if (is_sort(e, A) == 0)
	{
		if (e->print == 1)
			view_list(e);
		if (e->size_a <= 3)
			special_sort(e);
		else if (e->size_a < 50)
			normal_sort(e);
		else
		  {
		    list_to_tab(e);
		    merge_sort(e);
		  }
	}
	else
	{
		if (e->print == 1)
		{
			view_list(e);
			ft_putstr("Stack already sorted !\n");
		}
	}
}
