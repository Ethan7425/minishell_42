/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:40:47 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/24 09:21:21 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redir_init(t_token *token)
{
	while (token)
	{
		if (token->redir.r_in_type == INPUT_REDIR)
			input_redir_init(token);
		else if (token->redir.r_in_type == HEREDOC_REDIR)
			heredoc_redir_init(token);
		if (token->redir.r_out_type == OUTPUT_REDIR)
			output_redir_init(token);
		else if (token->redir.r_out_type == APPEND_REDIR)
			append_redir_init(token);
		token = token->next;
	}
}

void	input_redir_init(t_token *token)
{
	token->redir.infile_fd = open(token->redir.infile, O_RDONLY);
	if (token->redir.infile_fd < 0)
		token->redir.valid_infile = 0;
}

void	heredoc_pipe_init(int **heredoc_pipe)
{
	*heredoc_pipe = malloc(sizeof(int) * 2);
	if (!*heredoc_pipe)
		fatal_error("Error when trying to malloc() heredoc_pipe");
	if (pipe(*heredoc_pipe) < 0)
		fatal_error("Error when trying to pipe() heredoc_pipe");
}

void	heredoc_redir_init(t_token *token)
{
	int		*heredoc_pipe;
	char	*heredoc_input;
	char	*eof;

	eof = token->redir.infile;
	heredoc_pipe_init(&heredoc_pipe);
	heredoc_input = readline("> ");
	if (heredoc_input)
	{
		while (heredoc_input
			&& ft_strncmp(heredoc_input, eof, ft_strlen(eof)) != 0)
		{
			write(heredoc_pipe[1], heredoc_input, ft_strlen(heredoc_input));
			write(heredoc_pipe[1], "\n", 1);
			free(heredoc_input);
			heredoc_input = readline("> ");
		}
	}
	if (heredoc_input)
		free(heredoc_input);
	token->redir.infile_fd = heredoc_pipe[0];
	token->redir.heredoc_pipe = heredoc_pipe;
}

void	output_redir_init(t_token *token)
{
	char	*outfile;
	int		outfile_fd;

	outfile = token->redir.outfile;
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd < 0)
		fatal_error("Error when openning an outfile");
	token->redir.outfile_fd = outfile_fd;
}