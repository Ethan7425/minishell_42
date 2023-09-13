/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:59:28 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/13 18:30:13 by etbernar         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

// COLORS //
# define RESET_COLOR    "\033[0m"
# define RED     		"\033[0;31m"
# define GREEN    		"\033[0;32m"
# define YELLOW   		"\033[0;33m"
# define BLUE     		"\033[0;34m"
# define MAGENTA  		"\033[0;35m"
# define CYAN     		"\033[0;36m"
# define WHITE    		"\033[0;37m"

//STRUCTS

int		g_var;

// TODO : env struct

struct	s_token;

typedef struct s_minishell
{
	int		a;
	// int		b;
	// int		c;
	struct s_token	*token;
	int				tokens_nb;
	char			*prompt;
	char			**format_prompt;
	char			**envp_copy;
}	t_minishell;

typedef enum e_redir_in {
	NO_R_IN,
	INPUT_REDIR,
	HEREDOC_REDIR
}			t_redir_in;

typedef enum e_redir_out {
	NO_R_OUT,
	OUTPUT_REDIR,
	APPEND_REDIR
}			t_redir_out;

typedef struct s_redirt {
	char		*infile;
	char		*outfile;
	int			infile_fd;
	int			outfile_fd;
	int			valid_infile;
	int			*heredoc_fd;
	t_redir_in	r_in_type;
	t_redir_out	r_out_type;
}				t_redir;

typedef struct s_token
{
	int				buitlins_cmd;
	char			**commands;
	char			*value;
	int				token_id;
	t_redir			redir;
	struct s_token	*next;
}	t_token;

//FUNCTIONS

/* utils */
void	args_check(int argc);
int		is_space(int c);
int		is_redir_pipe(int c);
char	*extract_tokens(const char *str, int i, int *start);
char	*parse_character(const char *str, int i, int *start);
char	**ft_str_arr_cat(char **str_arr, const char *new_str);

/* main functions */
void	shell_init(t_minishell *ms, char **envp);

/* tokens */
void	format_redir(t_redir *redirec, char **in, int *i);
void	token_free(t_token *token);
int		make_token(t_token **tokens, char **format_prompt);

/* lexer */
char	**lexer(char const *str);
int		count_arg(const char *str);
char	*next_arg(const char *str, int *start);
void	word_nb_increase(const char *str, int i, int *word_nb);
void	update_quote_status(char cur_char, char *quote_status);

/* lexer */


/* parsing */
//void	parser(t_minishell *ms);

/* env */

/* export */

/* cd */

/* quotes */
bool	open_quotes(char *str);

/* syntax */
void	syntax_error(char *token);
bool	empty_input(char *in);
bool	syntax_ok(char *in);
bool	is_pipe(int c);
bool	is_redir(int c);
/* syntax utils */
bool	many_redir(char **in_syntaxed, int i, int len, int nb_redir);
bool	same_redir(char cur_redir, char prev_redir);
bool	valid_redir(char **in_syntaxed, int i);
bool	valid_pipe(char **in_syntaxed, int i);

/* errors */
int		print_error(char *msg);
void	fatal_error(char *msg);

/* signals */
void	signal_init(void (*signal_handler)(int));
void	prompt_handler(int sig);
void	exec_handler(int sig);

/* init */
void	prompt_init(t_minishell *ms);
t_token	*token_init(int token_id);

/* termios */
void	termios_init(void);

/* history */
void	history_init(void);

/* exec */
void	executionner(t_token *token, t_minishell *ms);
void	builtins(t_token *token, t_minishell *ms);

#endif
