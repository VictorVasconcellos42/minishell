# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:01:55 by vde-vasc          #+#    #+#              #
#    Updated: 2023/02/09 15:56:21 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRC		=	src/main.c

OBJ		=	${SRC:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

all: ${OBJ} $(NAME)

.c.o: 
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean: 
	rm -rf ${OBJ}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all
