#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/11 15:45:42 by ryabicho          #+#    #+#              #
#    Updated: 2017/04/15 03:20:29 by ryabicho         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
NAME_C = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./swap/srcs/
SRC_NAME =  main.c               \
			check_args.c         \
			op.c                 \
			op_push.c            \
			op_swap.c            \
			op_rotate.c          \
			op_reverse.c         \
			push_swap.c          \
			sort_stack.c         \
			little_stack.c       \
			utils.c              \
			search.c             \
			merge_sort.c		 \
			merge_helper.c		 \
			list_manager.c
OBJ_PATH = ./objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
CPPFLAGS = -I./swap/incs/ -I./libft/

SRC_PATH_C = ./check/srcs/
SRC_NAME_C =  main.c             \
			  utils.c            \
			  check.c            \
			  list_manager.c     \
			  op_push.c          \
			  op_swap.c          \
			  op_rotate.c        \
			  op_reverse.c       \
			  instructions.c
OBJ_PATH_C = ./objs_c/
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
SRC_C = $(addprefix $(SRC_PATH_C), $(SRC_NAME_C))
OBJ_C = $(addprefix $(OBJ_PATH_C), $(OBJ_NAME_C))
CPPFLAGS_C = -I./check/incs/ -I./libft/

LIBFT = -L ./libft/ -lft

all: $(NAME) $(NAME_C)

$(NAME): $(OBJ)
	@make -C libft/
	@echo "push_swap : Sources compiling..."
	$(CC) $(FLAGS) $(CPPFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo "push_swap : compile with success !"
$(NAME_C): $(OBJ_C)
	@echo "checker : Sources compiling..."
	$(CC) $(FLAGS) $(CPPFLAGS_C) -o $@ $(OBJ_C) $(LIBFT)
	@echo "checker : compile with success !"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
$(OBJ_PATH_C)%.o: $(SRC_PATH_C)%.c
	@mkdir $(OBJ_PATH_C) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS_C) -o $@ -c $<

clean:
	@make -C libft/ clean
	rm -f $(OBJ)
	@echo "Objects removed..."
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	rm -f $(OBJ_C)
	@rmdir $(OBJ_PATH_C) 2> /dev/null || true

fclean: clean
	@echo "push_swap binary removed..."
	@make -C libft/ fclean
	rm -f $(NAME) $(NAME_C)

re: fclean all
	@make -C libft/ re

.PHONY: all, clean, fclean, re
