# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marolive <marolive@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:01:55 by vde-vasc          #+#    #+#              #
#    Updated: 2023/03/29 13:01:16 by marolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	MAKEFILE VARIABLE	#

NAME	=	minishell

SRC		=	src/env.c src/builtin.c src/exec.c src/signal.c src/leak.c src/pipes.c src/init.c \
			src/utils.c src/cd.c src/pwd.c src/export.c src/expander.c src/tokenizer.c src/unset.c \
			src/lexer.c src/sentence.c src/prompt.c src/echo.c

OBJ		=	${SRC:.c=.o}

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

LIBFT	=	libft.a

LIBFT_DIR	=	libft/

#	COLORS	#

RED =	\033[0;31m
GREEN =	\033[0;32m
YELLOW =	\033[0;33m
BLUE =	\033[0;34m
END =	\033[0m

#	RULES	#

all: ${LIBFT} ${OBJ} $(NAME)

$(LIBFT):
	@make -C ${LIBFT_DIR}
	@cp $(addprefix ${LIBFT_DIR}, ${LIBFT}) .

.c.o:
	@${CC} ${CFLAGS} -I ~/.brew/opt/readline/include -c $< -o $@
#	@${CC} ${CFLAGS} -I/opt/homebrew/opt/readline/include -c $< -o $@

$(NAME): ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} ${LIBFT} ${OBJ} -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -lreadline -o ${NAME}
#	@${CC} ${CFLAGS} ${LIBFT} src/prompt.c -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include -lreadline ${OBJ} -o ${NAME}
	@echo "${GREEN}Minishell created!${END} ✅"

clean: 
	@rm -rf ${OBJ}
	@make clean -C ${LIBFT_DIR}
	@echo "${RED}Objects removed${END} 🚫"

fclean:	clean
	@rm -rf ${NAME}
	@rm -rf ${LIBFT}
	@make fclean -C ${LIBFT_DIR}
	@echo "${RED}Library removed${END} 🚫"

develop: $(LIBFT)
	cc -Wall -Wextra -Werror -g develop/shell.c ${SRC} -L ~/.brew/opt/readline/lib libft.a -I ~/.brew/opt/readline/include -lreadline -o tester

re:	fclean all

.PHONY: all fclean re clean develop
