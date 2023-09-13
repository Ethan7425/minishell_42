/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:38:52 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/13 14:15:35 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt_init(t_minishell *ms)
{
	ms->format_prompt = lexer(ms->prompt);
	printf("format promtp is %s\n", &ms->format_prompt[0][0]);
	printf("format promtp is %s\n", &ms->format_prompt[1][0]);
	// TODO expander for env var
	// ms->tokens_nb = make_token(&ms->token, ms->format_prompt);
}

t_token	*token_init(int token_id)
{
	t_token *new;
	new = malloc(sizeof(t_token));
	if (!new)
		fatal_error("malloc error !");
	new->token_id = token_id;
	new->buitlins_cmd = false;
	new->commands = NULL;
	new->redir.infile = NULL; 
	new->redir.outfile = NULL;
	new->redir.infile_fd = STDIN_FILENO;
	new->redir.outfile_fd = STDOUT_FILENO;
	new->redir.r_in_type = NO_R_IN;
	new->redir.r_out_type = NO_R_OUT;
	new->redir.valid_infile = true;
	new->next = NULL;
	new->redir.heredoc_fd = NULL;
	return(new);
}