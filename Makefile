# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:01:55 by vde-vasc          #+#    #+#              #
#    Updated: 2023/02/28 00:53:56 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	MAKEFILE VARIABLE	#

NAME	=	minishell

SRC		=	src/prompt.c src/env.c src/builtin.c

OBJ		=	${SRC:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

LIBFT	=	libft.a

LIBFT_DIR	=	libft/

#	RULES	#

all: ${OBJ} $(NAME)

$(LIBFT):
	@make -C ${LIBFT_DIR}
	@cp $(addprefix ${LIBFT_DIR}, ${LIBFT}) .

.c.o: 
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} ${LIBFT} -lreadline ${OBJ} -lreadline -o ${NAME}
	@echo "Minishell created! ✅"

clean: 
	@rm -rf ${OBJ}
	@make clean -C ${LIBFT_DIR}
	@echo "Objects removed 🚫"

fclean:	clean
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}
	@make fclean -C ${LIBFT_DIR}
	@echo "Library removed 🚫"

re:	fclean all

.PHONY: all fclean re clean
