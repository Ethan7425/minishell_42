/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:57:11 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/12 11:12:40 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	many_redir(char **in_syntaxed, int i, int len, int nb_redir)
{
	char	*error;

	if (nb_redir < 3)
		return (false);
	if (i < len - 1 && is_redir(*in_syntaxed[i + 1]))
	{
		error = ft_strjoin(in_syntaxed[i], in_syntaxed[i + 1]);
		syntax_error(error);
		free(error);
	}
	else
		syntax_error(in_syntaxed[i]);
	return (true);
}


bool	valid_pipe(char **in_syntaxed, int i)
{
	int	len;

	if (!in_syntaxed || !*in_syntaxed[i] || !is_pipe(*in_syntaxed[i]))
		return (false);
	len = ft_arr_len(in_syntaxed);
	if (i == 0
		|| (i < len - 1 && is_pipe(*in_syntaxed[i + 1]))
		|| i == len - 1)
	{
		syntax_error("|");
		return (false);
	}
	return (true);
}

bool	valid_redir(char **in_syntaxed, int i)
{
	int		len;
	int		nb_redir_in_a_row;
	char	redir;

	if (!in_syntaxed || !*in_syntaxed[i] || !is_redir(*in_syntaxed[i]))
		return (false);
	redir = *in_syntaxed[i];
	len =  ft_arr_len(in_syntaxed);
	nb_redir_in_a_row = 1;
	while (++i < len)
	{
		if (!is_redir(*in_syntaxed[i]) && !is_pipe(*in_syntaxed[i]))
			return (true);
		if (is_pipe(*in_syntaxed[i]))
			return (syntax_error("|"), false);
		nb_redir_in_a_row++;
		if (many_redir(in_syntaxed, i, len, nb_redir_in_a_row))
			return (false);
		if (!same_redir(*in_syntaxed[i], redir))
			return (false);
	}
	syntax_error("newline");
	return (false);
}

bool	same_redir(char cur_redir, char prev_redir)
{
	if (prev_redir != cur_redir)
	{
		syntax_error(&cur_redir);
		return (false);
	}
	return (true);
}
