#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vklaouse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/06 13:25:26 by vklaouse          #+#    #+#              #
#    Updated: 2016/04/23 02:07:25 by vklaouse         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strncpy.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isblank.c ft_islower.c \
	ft_isupper.c ft_isgraph.c ft_ispunct.c ft_abs.c get_next_line.c \
	ft_freejoin.c ft_printf.c ft_flags.c ft_flags_2.c ft_conv.c conv_d.c \
	conv_c.c conv_s.c conv_strange.c conv_u.c conv_2x.c ft_itoa_base.c \
	conv_o.c utils.c conv_p.c wrong_conv.c unicode.c conv_ws.c \
	ft_vector_init.c ft_vector_add.c ft_vector_set.c ft_vector_get.c \
	ft_vector_delat.c ft_vector_resize.c ft_vector_destroy.c ft_vector_insert.c \
	ft_vector_clear.c ft_vector_print.c ft_realloc.c

OBJ = $(SRC:.c=.o)

$(NAME):
		@gcc -Wall -Wextra -Werror -c $(SRC) -I ./include
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\033[33mLibft\033[m ====>\033[m \033[32mLibft.a :\033[m \033[36m  Ready!\033[m"

all: $(NAME)

clean:
		@rm -f $(OBJ)
		@echo "\033[33mLibft\033[m ====>\033[m \033[32mFiles .o :\033[m \033[36m rm -f!\033[m"

fclean: clean
		@rm -f $(NAME)
		@echo "\033[33mLibft\033[m ====>\033[m \033[32mlibft.a :\033[m \033[36m  rm -f!\033[m"

re: fclean all
