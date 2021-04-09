# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvaldeta <user@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 16:16:23 by mvaldeta          #+#    #+#              #
#    Updated: 2021/04/09 18:45:28 by mvaldeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIB: none
# SYN: A makefile is a file containing a set of directives used by a make build
# automation tool to generate a target/goal.
# DESC:
# (｡◕‿◕｡)
#
SRCS		= $(wildcard ./01_srcs/*.c)

OBJS		= ${SRCS:.c=.o}

INCDIR		= 00_includes

NAME		= libftprintf.a

CC			= gcc

ARRC		= ar rcs

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror 

.c.o: 
			${CC} -g ${CFLAGS} -c $^ -o ${<:.c=.o} -I${INCDIR}

$(NAME):	$(OBJS)
				${ARRC} $(NAME) $(OBJS)

all:		${NAME}

bonus:		${NAME}

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
