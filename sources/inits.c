/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:38:52 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/27 16:34:16 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt_init(t_minishell *ms)
{
	printf("init\n");
	ms->format_prompt = lexer(ms->prompt);
	printf("init2\n");
	// ms->format_prompt = expander(ms->format_prompt, ms->envp_copy);
	ms->tokens_nb = make_token(&ms->token, ms->format_prompt);
	printf("init3\n");
	executionner(ms->token, ms);
}

t_token	*token_init(int token_id)
{
	t_token	*new;

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
	new->redir.heredoc_pipe = NULL;
	return (new);
}

char	**ft_str_arr_init(void)
{
	char	**arr =	malloc(2 * sizeof(char *));

	if (arr)
	{
		arr[0] = NULL;
		arr[1] = NULL;
	}
	return (arr);
}
