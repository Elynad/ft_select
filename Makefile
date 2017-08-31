# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mameyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 12:11:53 by mameyer           #+#    #+#              #
#    Updated: 2017/08/31 17:28:23 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC =	main.c \
		parsing.c \
		errors.c \
		core.c \
		print.c \
		events.c \
		actions.c \
		signals.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT = libft/libft.a libdll/libdll.a

CC = clang

FLAGS = -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) -lncurses $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o :		$(SRC_PATH)/%.c
			$(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
			make -C ./libft/
			make -C ./libdll/

clean:
			rm -rf $(OBJ)
			make clean -C ./libft/
			make clean -C ./libdll/

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./libft/
			make fclean -C ./libdll/

re:			fclean all

.PHONY : all re clean fclean
