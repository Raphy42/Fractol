# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdantzer <rdantzer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:45:12 by rdantzer          #+#    #+#              #
#    Updated: 2015/04/27 19:46:27 by rdantzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

## Sources
DIR= srcs
SRC= $(shell find $(DIR) -type f -print)
SRC_FILES= $(shell basename -a $(SRC))
INC= -I includes

## Commands
CC= gcc
AR= ar

## Options
CFLAGS= -Wall -Werror -Wextra -fdiagnostics-color=always

## Aesthetics
RED= \033[31m
GREEN= \033[32m
RESET= \033[0m

## Obj
OBJ= $(SRC_FILES:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	@printf "$(RED)[LIBFT] Compiling sources...$(RESET)\t\t"
	@$(CC) $(CFLAGS) $(INC) -c $(SRC)
	@printf "$(GREEN)Done$(RESET)\n"
	@printf "$(RED)[LIBFT] Creating static library...$(RESET)\t"
	@$(AR) rcs $(NAME) $(OBJ)
	@printf "$(GREEN)Done$(RESET)\n"
	@printf "$(RED)[LIBFT] Cleaning directory...$(RESET)\t\t"
	@rm -f $(OBJ)
	@printf "$(GREEN)Done$(RESET)\n"

clean:
	@printf "$(RED)[LIBFT] Removing objects...$(RESET)\t\t"
	@rm -f $(OBJ)
	@printf "$(GREEN)Done$(RESET)\n"

fclean: clean
	@printf "$(RED)[LIBFT] Removing static library...$(RESET)\t"
	@rm -f $(NAME)
	@printf "$(GREEN)Done$(RESET)\n"

re: fclean all
