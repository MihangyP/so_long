# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 15:54:33 by pmihangy          #+#    #+#              #
#    Updated: 2024/06/09 16:10:42 by pmihangy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

all :
	make -C ./libft
	$(CC) main.c -o $(NAME) -Llibft -lft

clean :
	make -C ./libft clean
	rm -rf *.o

fclean : clean
	make -C ./libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
