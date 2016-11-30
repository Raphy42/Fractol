# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/31 02:47:15 by rdantzer          #+#    #+#              #
#    Updated: 2015/05/04 23:31:17 by rdantzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol
BUDDHA_NAME= buddhabrot

SRC= events.c fractals.c gradient.c init.c main.c opencl_helper.c\
	opencl_launcher.c threading.c multi_event.c
OBJ= $(SRC:.c=.o)
BUDDHA_SRC= buddhabrot.c
BUDDHA_OBJ= $(BUDDHA_SRC:.c=.o)

CC= gcc

CFLAGS= -Wall -Werror -Wextra -O3

FRAMEWORK= -framework OpenGL -framework OpenCL -framework Appkit
INCLUDE= -I ./libft/includes -I ./minilibx_macos
LIBRAIRIE= -L ./libft -lft -L ./minilibx_macos -lmlx


all: $(NAME)

$(NAME):
	make -C libft
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(SRC) $(INCLUDE) $(LIBRAIRIE) $(FRAMEWORK) -o $(NAME)
	$(CC) $(CFLAGS) $(BUDDHA_SRC) $(INCLUDE) $(LIBRAIRIE) $(FRAMEWORK) -o $(BUDDHA_NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(BUDDHA_OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BUDDHA_NAME)

re: fclean all

relib:
	make -C libft re
	make -C minilibx_macos
