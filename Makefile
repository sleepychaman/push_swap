#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryabicho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/11 15:45:42 by ryabicho          #+#    #+#              #
#    Updated: 2017/04/24 22:22:12 by ryabicho         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
NAME_C = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./swap/
SRC_NAME = push_swap.c\
				list.c\
				command.c\
				swap.c\
				push.c\
				rotate.c\
				rotate_rev.c\
				get.c\
				check.c\
				usecom.c\
				nouveau.c\
				pushback.c\
				sort.c\
				restore.c\
				move.c\
				tri.c

OAOBJ_PATH = ./objs/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
CPPFLAGS = -I./include/ -I./libft/

SRC_PATH_C = ./check/
SRC_NAME_C =  checker.c\
				list.c\
				command.c\
				swap.c\
				push.c\
				rotate.c\
				rotate_rev.c\
				get.c\
				check.c

OBJ_PATH_C = ./objs_c/
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
SRC_C = $(addprefix $(SRC_PATH_C), $(SRC_NAME_C))
OBJ_C = $(addprefix $(OBJ_PATH_C), $(OBJ_NAME_C))
CPPFLAGS_C = -I./include/ -I./libft/

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
