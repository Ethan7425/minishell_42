# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 11:06:27 by etbernar          #+#    #+#              #
#    Updated: 2023/09/14 09:14:03 by etbernar         ###   ########.fr        #
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

# Sources List
SRCS_LIST		=	check_suffix.c \
					ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_lstadd_back_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstmap_bonus.c \
					ft_lstnew_bonus.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_printf.c \
					ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strndup.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c \
					my_func.c \
					my_hexa_func.c \
					ft_arr_len.c \
					ft_free_char_2d.c \
					ft_arrdup.c \

# Output library name
NAME = libft.a

# Compiler and removal commands
CC = gcc
RM = rm -f

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Directory for object files
OBJS_DIR = objs/
OBJS_LIST = ${SRCS_LIST:.c=.o}

# List of object files
OBJS = ${addprefix ${OBJS_DIR}, ${OBJS_LIST}}

# Build all target
all: ${NAME}

# Create the object directory
${OBJS_DIR}:
	@mkdir -p ${OBJS_DIR}

# Compile each source file into object files
${OBJS_DIR}%.o: %.c | ${OBJS_DIR}
	@${CC} ${CFLAGS} -c $< -o $@

# Build the final library
${NAME}: ${OBJS_DIR} ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo ${GREEN}"[Libft] Compilation DONE"${RESET_COLOR}

# Clean the object files
clean:
	@rm -rf ${OBJS_DIR}
	@echo ${YELLOW}"[Libft] Cleaning DONE"${RESET_COLOR}

# Clean the object files and the library
fclean: 
	@rm -f ${NAME}
	@echo ${MAGENTA}"[Libft] Forced Cleaning DONE"${RESET_COLOR}

# Clean and rebuild
re: fclean all
	@echo ${RED}"[Libtf] REBOOTED"${RESET_COLOR}

.PHONY: clean fclean all re


