/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:15:46 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/13 14:52:34 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	make_token(t_token **tokens, char **format_prompt)
{
	t_token	*last_token;
	int		i;
	int		nb_token;

	nb_token = 1;
	*tokens = token_init(nb_token);
	last_token = *tokens;
	i = -1;
	while (format_prompt[++i])
	{
		if (format_prompt[i][0] == '|')
		{
			nb_token++;
			last_token->next = token_init(nb_token);
			last_token = last_token->next;
		}
		else if (format_prompt[i][0] == '<' || format_prompt[i][0] == '>')
			format_redir(&last_token->redir, format_prompt, &i);
		else
			last_token->commands = ft_str_arr_cat(last_token->commands,
						format_prompt[i]);
	}
	return (nb_token);
}

void	token_free(t_token *token)
{
	t_token	*next;

	while (token)
	{
		next = token->next;
		if (token->commands)
			ft_free_char_2d(token->commands);
		if (token->redir.infile)
			free(token->redir.infile);
		if (token->redir.outfile)
			free(token->redir.outfile);
		if (token->redir.heredoc_fd)
			free(token->redir.heredoc_fd);
		free(token);
		token = next;
	}
}

void	format_redir(t_redir *redirec, char **in, int *i)
{
	if (in[*i][0] == '<')
	{
		if (in[++(*i)][0] == '<')
		{
			redirec->infile = ft_strdup(in[++(*i)]);
			redirec->r_in_type = HEREDOC_REDIR;
			return ;
		}
		redirec->infile = ft_strdup(in[*i]);
		redirec->r_in_type = INPUT_REDIR;
	}
	else if (in[*i][0] == '>')
	{
		if (in[++(*i)][0] == '>')
		{
			redirec->outfile = ft_strdup(in[++(*i)]);
			redirec->r_out_type = APPEND_REDIR;
			return ;
		}
		redirec->outfile = ft_strdup(in[*i]);
		redirec->r_out_type = OUTPUT_REDIR;
	}
}
