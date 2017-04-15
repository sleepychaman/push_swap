/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:49:10 by ryabicho          #+#    #+#             */
/*   Updated: 2017/03/11 15:49:13 by ryabicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../../libft/libft.h"

# define MISSING_STACK  0
# define BAD_FORMAT     1
# define DUPLICATE_STR  2
# define BAD_ARGS       3
# define OVERFLOW       4
# define MALLOC_FAILED  5
# define BAD_INSTRUCT   6

# define STDIN          0
# define BUFSIZ         20
# define EOF            -1

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
	int					size_a;
	int					size_b;
}						t_env;

void					leave_program(int error, t_env *e);
void					check_args(t_env *e, char **args);
int						is_sort(t_env *e);

int						exec_instructions(t_env *e, char *directive);
int						read_instructions(t_env *e);
void					check_args(t_env *e, char **args);

void					add_link_a(t_env *e, int val);
void					add_link_b(t_env *e, int val);
void					remove_link_a(t_env *e);
void					remove_link_b(t_env *e);
void					view_list(t_env *e);

void					push_a(t_env *e);
void					push_b(t_env *e);
void					swap_a(t_env *e);
void					swap_b(t_env *e);
void					swap_swap(t_env *e);
void					rotate_rotate(t_env *e);
void					rotate_a(t_env *e);
void					rotate_b(t_env *e);
void					reverse_reverse_rotate(t_env *e);
void					reverse_rotate_a(t_env *e);
void					reverse_rotate_b(t_env *e);

#endif
