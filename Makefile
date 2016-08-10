#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/06 02:21:58 by vklaouse          #+#    #+#              #
#    Updated: 2016/05/04 20:52:49 by vklaouse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = main.c parse_file.c check_tubes.c ft_resolve.c algo.c clear.c display_result.c \
	tab_len.c

OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

$(NAME):
		@make -C libft
		@$(CC) -c $(CFLAGS) $(SRC)
		@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) libft/libft.a
		@echo "\033[33mLem-in\033[m ===>\033[m \033[32m./lem-in :\033[m \033[36m Ready!\033[m"

all: $(NAME)

clean:
		@$(RM) $(OBJ)
		@make -C libft/ clean
		@echo "\033[33mLem-in\033[m ===>\033[m \033[32mFiles .o :\033[m \033[36m rm -f!\033[m"

fclean: clean
		@$(RM) $(NAME)
		@make -C libft/ fclean
		@echo "\033[33mLem-in\033[m ===>\033[m \033[32m./lem-in :\033[m \033[36m rm -f!\033[m"

re: fclean all

.PHONY: all clean fclean re