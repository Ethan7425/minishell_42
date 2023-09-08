# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:06:27 by etbernar          #+#    #+#              #
#    Updated: 2023/09/08 15:18:05 by etbernar         ###   ########.fr        #
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


SRCS = ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
	ft_memset.c ft_isalpha.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
	ft_putendl_fd.c ft_printf.c check_suffix.c my_func.c ft_putchar.c my_hexa_func.c \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

.c.o:
	@(${CC} ${CFLAGS} -c $< -o ${<:.c=.o})

${NAME}: ${OBJS}
	@(ar rcs ${NAME} ${OBJS})
	@echo ${GREEN}"[Libft] Compilation DONE"${RESET_COLOR}

clean:
	@(${RM} ${OBJS})
	@echo ${YELLOW}"[Libft] Cleaning DONE"${RESET_COLOR}

fclean: 
	@(${RM} ${NAME})
	@echo ${MAGENTA}"[Libft] Force Cleaning DONE"${RESET_COLOR}

re: fclean all

.PHONY: clean fclean all re
