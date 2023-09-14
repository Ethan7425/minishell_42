# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 11:29:32 by etbernar          #+#    #+#              #
#    Updated: 2023/09/14 13:21:36 by etbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #
RESET_COLOR = "\033[0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
MAGENTA = "\033[0;35m"
CYAN = "\033[0;36m"
WHITE = "\033[0;37m"

NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -I$(HOME)/.brew/opt/readline/include

ASAN_FLAGS  = -fsanitize=address

INCL_PATH	=	-Iincl/ \
				-I$(HOME)/.brew/opt/readline/include

LIBS		=	-Llibft -lft -lreadline \
				-L$(HOME)/.brew/opt/readline/lib

LIBFT		=	libft.a

SRCS_DIR	=	sources/
OBJS_DIR	=	objs/

SRCS_LIST	=	main.c \
				signals.c \
				history.c \
				utils.c \
				utils2.c \
				utils_syntax.c \
				errors.c \
				termios.c \
				lexer.c \
				exec.c \
				inits.c \
				syntax.c \
				quotes.c \
				tokens.c \
				free.c \
				echo.c \
				
OBJS_LIST	=	${SRCS_LIST:.c=.o}

OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

READLINE	=	-lreadline -L$(HOME)/.brew/opt/readline/lib

all:			${LIBFT} ${NAME}

${OBJS_DIR}:
				@(mkdir ${OBJS_DIR})

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
				@(${CC} ${CFLAGS} ${INCL_PATH} -c $^ -o $@)

asan: CFLAGS += ${ASAN_FLAGS}
asan: clean ${OBJS_DIR} ${OBJS}
	@(${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME})
	@echo ${GREEN}"[Minishell (ASan)] Compilation DONE"${RESET_COLOR}


${NAME}:		${OBJS_DIR} ${OBJS}
				@(${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME})
				@echo ${GREEN}"[Minishell] Compilation DONE"${RESET_COLOR}

${LIBFT}:
				@($(MAKE) -C libft)

clean:
				@(rm -rf ${OBJS_DIR})
				@($(MAKE) -C libft clean)
				@echo ${YELLOW}"[Minishell] Cleaning DONE"${RESET_COLOR}

fclean:			clean
				@(rm -f ${NAME})
				@($(MAKE) -C libft fclean)
				@echo ${MAGENTA}"[Minishell] Forced Cleaning DONE"${RESET_COLOR}

re:				fclean all
				@echo ${RED}"[Minishell] REBOOTED"${RESET_COLOR}
				
.PHONY:			all clean fclean re