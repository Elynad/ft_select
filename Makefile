# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mameyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 12:11:53 by mameyer           #+#    #+#              #
#    Updated: 2017/08/25 05:35:14 by mameyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	main.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT = libft/libft.a

CC = clang

FLAGS = -Wall -g -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

%.o :		$(SRC_PATH)/%.c
			$(CC) -o $@ -c $< $(FLAGS)

$(LIBFT):
			make -C ./libft/

clean:
			rm -rf $(OBJ)
			make clean -C ./libft/

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./libft/

re:			fclean all

.PHONY : all re clean fclean
