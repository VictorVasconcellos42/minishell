# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:01:55 by vde-vasc          #+#    #+#              #
#    Updated: 2023/02/09 17:41:12 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	MAKEFILE VARIABLE	#

NAME	=	minishell

SRC		=	src/main.c

OBJ		=	${SRC:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

#	RULES	#

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
