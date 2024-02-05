# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luiberna <luiberna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 12:32:15 by luiberna          #+#    #+#              #
#    Updated: 2024/02/05 16:24:12 by luiberna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c verifiers.c \
	   Bestfriend/bestfriend.c \
	   Cost/cost.c Cost/move_less_cost.c \
	   Moves/swap.c Moves/push.c Moves/rotate.c Moves/rerotate.c \
	   Sort/sort.c Sort/final_sort.c \
	   Free/free.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./Libft
	$(CC) $(OBJS) ./Libft/libft.a -o $(NAME)

clean:
		make clean -C ./Libft
		rm -f $(OBJS)

fclean: clean
		make fclean -C ./Libft
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
