# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/09 15:01:55 by vde-vasc          #+#    #+#              #
#    Updated: 2023/04/10 09:35:01 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	MAKEFILE VARIABLE	#

NAME	=	minishell

PARSER	= $(addprefix Parser/, prompt.c tokenizer.c expander.c lexer.c parser.c parser_utils.c sentence.c)

UTILS	= $(addprefix Utils/, init.c leak.c redirect_boolean.c token_boolean.c signal.c utils.c)

BUILTIN	= $(addprefix Builtin/, cd.c echo.c env.c export.c pwd.c unset.c builtin.c)

EXECUTOR	= $(addprefix Executor/, executor.c)

REDIRECTS	=	$(addprefix Redirects/, redirect.c pipes.c)

DEVELOP	=	$(addprefix develop/, exec.c quote.c)

SRC		=	$(addprefix src/, ${PARSER} ${UTILS} ${BUILTIN} ${EXECUTOR} ${REDIRECTS})

OBJ		=	${SRC:.c=.o} ${DEVELOP:.c=.o}

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
	@${CC} ${CFLAGS} -I ~/.brew/opt/readline/include -c $< -o $@ #Mac 42
#	@${CC} ${CFLAGS} -lreadline -c $< -o $@ #Linux
#	@${CC} ${CFLAGS} -I/opt/homebrew/opt/readline/include -c $< -o $@ #Mac M1

$(NAME): ${OBJ} ${LIBFT}
	@${CC} ${CFLAGS} ${LIBFT} ${OBJ} -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -lreadline -o ${NAME} #Mac 42
#	@${CC} ${CFLAGS} ${LIBFT} src/prompt.c -L/opt/homebrew/opt/readline/lib -I/opt/homebrew/opt/readline/include -lreadline ${OBJ} -o ${NAME} #Mac M1
#	@${CC} ${CFLAGS} ${OBJ} ${LIBFT} -lreadline -o ${NAME} #Linux
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
	cc -Wall -Wextra -Werror -g develop/*.c ${SRC} -L ~/.brew/opt/readline/lib libft.a -I ~/.brew/opt/readline/include -lreadline -o tester

re:	fclean all

.PHONY: all fclean re clean develop
