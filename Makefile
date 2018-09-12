# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 12:37:27 by kmieshko          #+#    #+#              #
#    Updated: 2018/08/30 12:37:28 by kmieshko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = kmieshko.filler

SRCS = 	./srcs/ft_create.c \
		./srcs/ft_fill_struct.c \
		./srcs/ft_small_map.c \
		./srcs/ft_big_map.c \
		./srcs/ft_is_placeable.c \
		./srcs/ft_additional.c \
		./srcs/main.c

OBJ = $(SRCS:.c=.o)

LIB = ./libft/libft.a

INCL = -I ./incl/

COMPILE = gcc -c -g

FLAGS = -Wall -Wextra -Werror -O3 -march=native

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(OBJ) $(FLAGS) $(LIB) -o $(NAME)

%.o: %.c
	$(COMPILE) -o $@ $< $(FLAGS) $(INCL)
	
clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft