# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldeta <mvaldeta@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 16:16:23 by mvaldeta          #+#    #+#              #
#    Updated: 2021/03/06 17:16:03 by mvaldeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIB: none
# SYN: A makefile is a file containing a set of directives used by a make build
# automation tool to generate a target/goal.
# DESC:
# (｡◕‿◕｡)
#
SRC =	conv_numbers.c/
		conv_operator.c/
		ft_printf.c/
		ft_utilities.c/
		print_operator.c/

OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
		$(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

so:
	$(CC) -fPIC -c $(CFLAGS) $(SRC)
	gcc -shared -o libft.so $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus
