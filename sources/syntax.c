/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:40:05 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/12 11:20:52 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	syntax_error(char *token)
{
	printf(RED "Minishell : error near token '%s'\n"RESET_COLOR, token);
}

bool	empty_input(char *in)
{
	int	i;
	int	len;

	if (!in || !(*in))
		return (true);
	len = ft_strlen(in);
	if (!len)
		return (true);
	i = 0;
	while (in[i] && is_space(in[i]))
		i++;
	if (i == len)
		return (true);
	return (false);
}

bool	syntax_ok(char *in)
{
	int 	i;
	char	**in_syntaxed;

	i = -1;
	if (open_quotes(in))
		return(g_var = 258, false);
	if (empty_input(in))
		return(false);
	in_syntaxed = lexer(in);
	if (!in_syntaxed)
		return(ft_free_char_2d(in_syntaxed), false);
	while(in_syntaxed[++i])
	{
		if (is_pipe(in_syntaxed[i][0]))
		{
			if (!valid_pipe(in_syntaxed, i))
				return(ft_free_char_2d(in_syntaxed), false);
		}
		else if (is_redir(in_syntaxed[i][0]))
		{
			if (!valid_redir(in_syntaxed, i))
				return(ft_free_char_2d(in_syntaxed), false);
		}
	}
	return (ft_free_char_2d(in_syntaxed), true);
}

bool	is_pipe(int c)
{
	return(c == '|');
}

bool	is_redir(int c)
{
	return(c == '<' || c == '>');
}

