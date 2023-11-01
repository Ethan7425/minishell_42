/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:59:28 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/31 17:19:38 by etbernar         ###   ########.fr       */
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

// # define EXIT_GENERAL_ERROR 2
// # define EXIT_CMD_NOT_FOUND 127
// # define EXIT_CMD_INTERRUPTED 130
// # define EXIT_ERROR_FORMAT 258

int		g_var;

//STRUCTS

//TODO : env struct

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
	int				**pipe_fd;
}	t_minishell;

typedef enum e_redir_in 
{
	NO_R_IN,
	INPUT_REDIR,
	HEREDOC_REDIR
}			t_redir_in;

typedef enum e_redir_out 
{
	NO_R_OUT,
	OUTPUT_REDIR,
	APPEND_REDIR
}			t_redir_out;

typedef struct s_redir 
{
	char		*infile;
	char		*outfile;
	int			infile_fd;
	int			outfile_fd;
	int			valid_infile;
	int			*heredoc_pipe;
	t_redir_in	r_in_type;
	t_redir_out	r_out_type;
}				t_redir;

typedef struct s_token
{
	int			buitlins_cmd;
	char			**commands;
	//char			*value;
	int 			valid_cmd;
	int				token_id;
	int				builtin;
	int				pid;
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
int		is_builtin(t_token *token);

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

/* free */
void	free_all(t_minishell *ms);


/* exit */
void	ft_exit(t_token *token);
int		is_numeric(char *str);

/* echo */
void	echo(t_token *token);

/* export */

/* env */
void	set_env(char ***env_var);
void	ft_env(t_minishell *ms);


int		ft_find_index_env(const char *name, char **envp_copy);
bool	valid_name(const char *name);
char	*ft_getenv(const char *name, char **envp_copy);

/* expander */
char	**expander(char **line_elem, char **envp_copy);
char	*process_env_var(char *arg, char **envp_copy);
int		handle_env_var(char **arg, char **envp_copy, int i);
char	*ft_get_env_name(char *arg, int *i, int env_start_ind);
int		replace_env_var(char **input, int start, int end, char *env_var);



/* quotes */
bool	open_quotes(char *str);
void	quote_status(char act_char, char *quote);
char	*rm_quotes(char *str);


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
char **ft_str_arr_init(void);

/* termios */
void	termios_init(void);

/* history */
void	history_init(void);

/* exec */
void	executionner(t_token *token, t_minishell *ms);
void	builtins(t_token *token, t_minishell *ms);
int	external(t_token *token, t_minishell *ms);

/* childs */
int	childable(t_token *token);
void	make_child(t_token *token, t_minishell *ms);
void	check_infile(t_token *token, t_minishell *ms);
void	check_cmd_validity(t_token *token, t_minishell *ms);
void	set_dups(t_token *token);
void	clean_up(t_token *token, t_minishell *ms);
void	wait_children(t_token *token);


/* redirection */
void	append_redir_init(t_token *token);
void	close_redir_fd(t_token *token);
void	output_redir_init(t_token *token);
void	heredoc_redir_init(t_token *token);
void	heredoc_pipe_init(int **heredoc_pipe);
void	input_redir_init(t_token *token);
void	redir_init(t_token *token);

/* path */
void	init_path_tokens(t_token *token, char **envp_cpy);
int		search_cmd_in_path(char **path_arr, t_token *token);
int		init_cmd_path(t_token *token, char **envp_cpy);

#endif
