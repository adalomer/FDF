# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 12:56:30 by omadali           #+#    #+#              #
#    Updated: 2025/02/18 22:57:45 by omadali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = srcs/main.c srcs/map_parser.c srcs/draw.c srcs/events.c srcs/utils.c srcs2/ft_split.c srcs2/get_next_line_utils.c srcs2/get_next_line.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re