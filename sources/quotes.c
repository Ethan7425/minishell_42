/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:46:40 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/25 12:55:55 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	open_quotes(char *str)
{
	int	open_quote;

	open_quote = 0;
	while (str && *str)
	{
		if (!open_quote && (*str == '\'' || *str == '\"'))
			open_quote = *str;
		else if (*str == open_quote)
			open_quote = 0;
		str++;
	}
	if (open_quote)
	{
		ft_printf ("Error : quote open\n");
		return (true);
	}
	return (false);
}

char	*rm_quotes(char *str)
{
	char	*res;
	int		i;
	int		j;
	char	open_quote;

	if (!str)
		return (NULL);
	res = (char *)malloc(ft_strlen(str) + 1);
	if (!res)
		fatal_error("memory allocation error");
	i = -1;
	j = 0;
	open_quote = 0;
	while (str[++i])
	{
		if ((str[i] == '\"' || str[i] == '\'') && !open_quote)
			open_quote = str[i];
		else if (str[i] == open_quote)
			open_quote = 0;
		else
			res[j++] = str[i];
	}
	res[j] = '\0';
	free(str);
	return (res);
}

void	quote_status(char act_char, char *quote)
{
	if (!*quote && (act_char == '\'' || act_char == '\"'))
		*quote = act_char;
	else if (act_char == *quote)
		*quote = 0;
}