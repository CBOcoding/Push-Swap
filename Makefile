# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cborrome <cborrome@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 13:57:25 by cborrome          #+#    #+#              #
#    Updated: 2025/02/18 10:11:36 by cborrome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = \
		main.c \
		validation.c \
		libft_split.c \
		libft_atoi.c \
		libft_strdup.c \
		populate_stack.c \
		free_error.c \
		initialize_sorting.c \
		op_push.c \
		op_swap.c \
		op_rotate.c \
		op_reverse_rotate.c \
		sort5.c \
		sort_big.c \
		execute_cheapest_move.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

GREEN = \e[1;32m
PURPLE = \e[1;35m
RESET = \033[0m

100: $(NAME)
	@MAX=0; \
	for i in $(shell seq 1 500); do \
		ARGS=$$(shuf -i 1-2147483647 -n 100 | tr '\n' ' '); \
		RESULT=$$(./$(NAME) $$ARGS | wc -l); \
		if [ $$RESULT -gt $$MAX ]; then \
			MAX=$$RESULT; \
		fi; \
		COMPLETION=$$(($$i * 100 / 500)); \
		printf "\r%% Progress: $$COMPLETION%%"; \
		sleep 0.01; \
	done; \
	echo "$(PURPLE)\nTarget Operations: 700\nWorst Case Operations: $$MAX$(RESET)"

500: $(NAME)
	@MAX=0; \
	for i in $(shell seq 1 100); do \
		ARGS=$$(shuf -i 1-2147483647 -n 500 | tr '\n' ' '); \
		RESULT=$$(./$(NAME) $$ARGS | wc -l); \
		if [ $$RESULT -gt $$MAX ]; then \
			MAX=$$RESULT; \
		fi; \
		COMPLETION=$$(($$i)); \
		printf "\r%% Progress: $$COMPLETION%%"; \
		sleep 0.01; \
	done; \
	echo "$(PURPLE)\nTarget Operations: 5500\nWorst Case Operations: $$MAX$(RESET)"

100check: $(NAME)
	@for i in $(shell seq 1 10); do \
		ARGS=$$(shuf -i 1-2147483647 -n 100 | tr '\n' ' '); \
		./$(NAME) $$ARGS | ./checker_Mac $$ARGS; \
	done

# ./$(NAME) $$ARGS | ./checker_linux $$ARGS;

500check: $(NAME)
	@for i in $(shell seq 1 10); do \
		ARGS=$$(shuf -i 1-2147483647 -n 500 | tr '\n' ' '); \
		./$(NAME) $$ARGS | ./checker_Mac $$ARGS; \
	done

# ./$(NAME) $$ARGS | ./checker_linux $$ARGS;

.PHONY : all clean fclean re
