# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 15:54:33 by pmihangy          #+#    #+#              #
#    Updated: 2024/06/10 11:10:47 by pmihangy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS_FILES = main.c args_errors.c catch_map.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_LIBS = -lmlx_Linux -lX11 -lXext

all :
	make -C ./libft
	make -C ./minilibx
	$(CC) $(SRCS_FILES) -o $(NAME) -Llibft -lft -Lminilibx $(MLX_LIBS)

clean :
	make -C ./libft clean
	make -C ./minilibx clean
	rm -rf *.o

fclean : clean
	make -C ./libft fclean
	rm -rf ./minilibx/*.a
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
