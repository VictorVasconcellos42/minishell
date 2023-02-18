# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:01:55 by vde-vasc          #+#    #+#              #
#    Updated: 2023/02/16 11:40:23 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	MAKEFILE VARIABLE	#

NAME	=	minishell

SRC		=	src/prompt.c src/env.c src/builtin.c

OBJ		=	${SRC:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

#	RULES	#

all: ${OBJ} $(NAME)

.c.o: 
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJ}
	${CC} ${CFLAGS} -lreadline ${OBJ} libft.a -lreadline -o ${NAME}

clean: 
	rm -rf ${OBJ}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all
