/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:44:55 by ryabicho          #+#    #+#             */
/*   Updated: 2017/04/15 03:19:31 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../libft/libft.h"

# define MISSING_STACK  0
# define BAD_FORMAT     1
# define DUPLICATE_STR  2
# define BAD_ARGS       3
# define OVERFLOW       4
# define MALLOC_FAILED  5
# define BAD_INSTRUCT   6

# define CNT           register unsigned int

# define A_FIRST        e->stack_a->data
# define B_FIRST        e->stack_b->data
# define A_SECOND       e->stack_a->next->data
# define B_SECOND       e->stack_b->next->data
# define A_LAST         e->stack_a->prev->data
# define B_LAST         e->stack_b->prev->data
# define A_BLAST        e->stack_a->prev->prev->data
# define B_BLAST        e->stack_b->prev->prev->data

# define A   1
# define B   0

typedef struct			s_link
{
	struct s_link		*prev;
	struct s_link		*next;
	int					data;
}						t_link;

typedef struct			s_env
{
	t_link				*stack_a;
	t_link				*stack_b;
	int					count;
	int					op;
	int					size_a;
	int					size_b;
	int					middle;
	int					min_pos;
	int					min;
	int					pront : 1;
	int					print;
}						t_env;

void					push_swap(t_env *e);

void					special_sort(t_env *e);
void					normal_sort(t_env *e);
void					check_special(t_env *e);
void					move_to_a(t_env *e);
void					move_to_b(t_env *e);

void					do_sort(t_env *e, int *len);
void					sort_a_on_b(t_env *e, int len);
void					merge_b_to_a(t_env *e);
void					merge_sort(t_env *e);
int						*find_len(t_env *e, int x);

void					set_len_vals(t_env *e, int *len, int y);
void					rotate_individuals(t_env *e, int *len);
void					sort_big_a_on_b(t_env *e, int len, int x, int *tmp);

void					check_args(t_env *e, char **args);
void					check_duplicate(t_env *e, char **list);

void					add_link_a(t_env *e, int val);
void					add_link_b(t_env *e, int val);
void					remove_link_a(t_env *e);
void					remove_link_b(t_env *e);
void					view_list(t_env *e);

void					update_mid(t_env *e);
void					search_min(t_env *e);
void					search_max(t_env *e);

void					add_operation(char *op);

int						is_sort(t_env *e, int stack);
void					leave_program(int error, t_env *e);

void					swap_a(t_env *e);
void					swap_b(t_env *e);
void					swap_swap(t_env *e);
void					rotate_a(t_env *e);
void					rotate_b(t_env *e);
void					rotate_rotate(t_env *e);
void					reverse_a(t_env *e);
void					reverse_b(t_env *e);
void					reverse_reverse(t_env *e);
void					push_a(t_env *e);
void					push_b(t_env *e);

#endif
