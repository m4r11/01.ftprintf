# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 16:16:23 by mvaldeta          #+#    #+#              #
#    Updated: 2021/03/08 21:09:04 by mvaldeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIB: none
# SYN: A makefile is a file containing a set of directives used by a make build
# automation tool to generate a target/goal.
# DESC:
# (｡◕‿◕｡)
#
SRC =	conv_numbers.c\
		ft_printf.c\
		ft_utilities.c\
		conv_operator.c\

OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -f

NAME = libftprintf.a

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
		$(NAME)

so:
	$(CC) -fPIC -c $(CFLAGS) $(SRC)
	gcc -shared -o libftprintf.so $(OBJ)

.PHONY: all clean fclean re bonus
