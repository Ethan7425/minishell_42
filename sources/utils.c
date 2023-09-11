/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:37:01 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/11 14:52:00 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	args_check(int argc)
{
	if (argc > 1)
	{
		print_error(RED "No args except ./minishell" RED);
		exit(1);
	}
}

int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_redir_pipe(int c)
{
	return (c == '|' || c == '<' || c == '>');
}

char	*extract_tokens(const char *str, int i, int *start)
{
	int		length;
	char	*token;

	length = i - *start;
	if (length > 0)
	{
		token = ft_strndup(str + *start, length);
		if (!token)
			fatal_error("malloc error\n");
		*start = i;
	}
	else
	{
		token = ft_strndup(str + *start, 1);
		if (!token)
			fatal_error("malloc error\n");
		*start = i + 1;
	}
	return (token);
}

char	*parse_character(const char *str, int i, int *start)
{
	if (is_redir_pipe(str[i]) || is_space(str[i]))
		return (extract_tokens(str, i, start));
	else
		return (NULL);
}

void	update_quote_status(char cur_char, char *quote_status)
{
	if (!*quote_status && (cur_char == '\'' || cur_char == '\"'))
		*quote_status = cur_char;
	else if (cur_char == *quote_status)
		*quote_status = 0;
}
