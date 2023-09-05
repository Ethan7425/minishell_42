/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:59:28 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/05 21:44:04 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/syslimits.h>
#include <readline/readline.h>
#include <readline/history.h>
# include "../libft/libft.h"

// COLORS //
#define RESET_COLOR     "\033[0m"
#define RED     		"\033[0;31m"
#define GREEN    		"\033[0;32m"
#define YELLOW   		"\033[0;33m"
#define BLUE     		"\033[0;34m"
#define MAGENTA  		"\033[0;35m"
#define CYAN     		"\033[0;36m"
#define WHITE    		"\033[0;37m"

//STRUCTS

int		g_cat;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_minishell
{

	char 	*prompt;
	char 	**env;
}	t_minishell;

//FUNCTIONS
/* main functions */

/* builtin-commands */

/* parsing */

/* env */

/* export */

/* cd */

/* signals */
void	signal_handler(int signum);
void	signal_init(void);

/* init */


#endif