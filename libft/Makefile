# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-vasc <vde-vasc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 18:25:11 by vde-vasc          #+#    #+#              #
#    Updated: 2023/02/16 00:58:05 by vde-vasc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=   ft_isascii.c ft_isprint.c ft_strlen.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_atoi.c ft_bzero.c ft_memset.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_strtrim.c \
			ft_split.c ft_itoa.c ft_putendl_fd.c ft_putnbr_fd.c argument_case.c printf_utils.c ft_printf.c\
			ft_strmapi.c ft_striteri.c get_next_line.c get_next_line_utils.c

BONUS_S	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	= ${BONUS_S:.c=.o}

NAME	=	libft.a

LIBNAME	=	-lft

CC	=	cc

AR	=	ar

LBFLAGS	=	rcs

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< 

all:	$(NAME)
	
$(NAME):	${OBJS}
	${AR} ${LBFLAGS} $(NAME) ${OBJS}

bonus: ${NAME} ${OBJS_BONUS}
	${AR} ${LBFLAGS} $(NAME) ${OBJS_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}
	
fclean:	clean
	${RM} $(NAME)
	
re:	fclean all

.PHONY	=	all clean fclean re
