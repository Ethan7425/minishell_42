# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 16:01:12 by etbernar          #+#    #+#              #
#    Updated: 2023/08/30 18:47:44 by etbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS #

# OUTPUT #
NAME		= minishell

# COMMANDS #
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf


all: ${NAME}

clean:

fclean:	clean

re: fclean all

.PHONY: all clean fclean re