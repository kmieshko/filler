# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 12:42:59 by kmieshko          #+#    #+#              #
#    Updated: 2018/09/13 12:43:00 by kmieshko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual

SRCS = main.c \
		ft_draw_map.c \
		ft_draw_field_cells.c \
		ft_pixel_put.c \
		ft_get_struct.c \
		ft_print_text.c \
		ft_manage.c

OBJ = $(SRCS:.c=.o)

LIB = ../libft/libft.a

COMPILE = gcc -c

FLAGS = -Wall -Werror -Wextra

FLAGS_GR = -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(FLAGS) $(FLAGS_GR) $(LIB) -o $(NAME)

%.o: %.c
	$(COMPILE) -o $@ $< $(FLAGS)
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all