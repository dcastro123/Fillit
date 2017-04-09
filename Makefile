# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/31 15:36:14 by dcastro-          #+#    #+#              #
#    Updated: 2017/03/13 14:27:25 by dcastro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc -Wall -Werror -Wextra

INCL = -I /fillit.h

SRC = src/main.c src/tetri_read.c src/tetri_solve.c src/tetri_chk.c\
	 src/fillit_map.c src/tetris_struct.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	make all -C libft
	 @$(CC) $(INCL) -L libft/ -lft $(SRC) -o $(NAME)

clean :
	make clean -C libft
	@/bin/rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean
