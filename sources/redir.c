/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:26:30 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/17 08:36:38 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	close_redir_fd(t_token *token)
{
	while (token)
	{
		if (token->redir.r_in_type == INPUT_REDIR
			&& token->redir.valid_infile == true)
			if (close(token->redir.infile_fd) < 0)
				fatal_error("Error when trying to close an in-file");
		if (token->redir.r_out_type == OUTPUT_REDIR
			|| token->redir.r_out_type == APPEND_REDIR)
			if (close(token->redir.outfile_fd) < 0)
				fatal_error("Error when trying to close an out-file");
		token = token->next;
	}
}

void	append_redir_init(t_token *token)
{
	char	*outfile;
	int		outfile_fd;

	outfile = token->redir.outfile;
	outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outfile_fd < 0)
		fatal_error("Error when openning an outfile");
	token->redir.outfile_fd = outfile_fd;
}
