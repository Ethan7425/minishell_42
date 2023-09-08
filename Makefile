# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:01:12 by etbernar          #+#    #+#              #
#    Updated: 2023/09/07 23:06:49 by etbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #

# NAME		= minishell
# SRC = $(addprefix sources/, main.c)
# OBJ := $(SRC:%.c=%.o)

# INCL_PATH	=	-Iincl/ \
# 				-I$(HOME)/.brew/opt/readline/include

# # COMMANDS #
# CC			= gcc
# CCFLAGS     = -Wall -Wextra -Werror -I/usr/include/readline
# LDFLAGS     = -lreadline -L/usr/include/readline -lncurses
# RM			= rm -rf

# $(NAME): $(OBJ)
# 	$(CC) $(CCFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

# %.o: %.c
# 	$(CC) $(CCFLAGS) ${INCL_PATH} -c $< -o $@

# all: $(NAME)

# clean:
# 	rm -f $(OBJ)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

NAME		=	minishell

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -I$(HOME)/.brew/opt/readline/include

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
				parser.c \
				utils.c \
				exit.c \
				termios.c \
				
OBJS_LIST	=	${SRCS_LIST:.c=.o}

OBJS		=	${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

READLINE	=	-lreadline -L$(HOME)/.brew/opt/readline/lib

all:			${LIBFT} ${NAME}

${OBJS_DIR}:
				mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
				${CC} ${CFLAGS} ${INCL_PATH} -c $^ -o $@

${NAME}:		${OBJS_DIR} ${OBJS}
				${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

${LIBFT}:
				$(MAKE) -C libft

clean:
				rm -rf ${OBJS_DIR}
				$(MAKE) -C libft clean

fclean:			clean
				rm -f ${NAME}
				$(MAKE) -C libft fclean

re:				fclean all

.PHONY:			all clean fclean re