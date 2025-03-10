# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omadali <omadali@student.42kocaeli.com.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 12:56:30 by omadali           #+#    #+#              #
#    Updated: 2025/03/05 01:35:18 by omadali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = srcs/main.c srcs/map_parser.c srcs/draw.c srcs/events.c srcs/map_memory.c srcs/map_dimensions.c srcs/utils.c srcs2/ft_split.c srcs2/get_next_line_utils.c srcs2/get_next_line.c srcs/utils2.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	make -C minilibx_linux 
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	make -C minilibx_linux clean
	rm -f $(OBJS)

fclean: clean
	make -C minilibx_linux clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
