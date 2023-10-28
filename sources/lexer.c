/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:23:19 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/27 19:07:10 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_arg(const char *str)
{
	int		i;
	int		word_nb;
	char	quote_status;

	if (!str)
		return (0);
	word_nb = 0;
	quote_status = 0;
	i = -1;
	while (str[++i])
	{
		update_quote_status(str[i], &quote_status);
		if (!quote_status)
			word_nb_increase(str, i, &word_nb);
	}
	if (!is_space(str[i - 1]) && !is_redir_pipe(str[i - 1]))
		word_nb++;
	return (word_nb);
}

char	*next_arg(const char *str, int *start)
{
	int		i;
	char	quote_status;
	char	*word;

	quote_status = 0;
	i = *start;
	if (!str || !str[i])
		return (NULL);
	while (is_space(str[i]))
		i++;
	*start = i;
	while (str[i])
	{
		update_quote_status(str[i], &quote_status);
		if (!quote_status)
		{
			word = parse_character(str, i, start);
			if (word)
				return (word);
		}
		i++;
	}
	return (extract_tokens(str, i, start));
}

char	**lexer(char const *str)
{
	int		i;
	int		word_nb_cpt;
	int		nb_args;
	char	**splited;
	if (!str)
		return (NULL);
	nb_args = count_arg(str);
	splited = malloc((nb_args + 1) * sizeof(char *));
	if (!splited)
		fatal_error("malloc error\n");
	i = 0;
	word_nb_cpt = 0;
	while (word_nb_cpt < nb_args)
	{
		splited[word_nb_cpt] = next_arg(str, &i);
		if (!splited[word_nb_cpt])
			return (NULL);
		word_nb_cpt++;
	}
	splited[nb_args] = NULL;
	return (splited);
}

void	word_nb_increase(const char *str, int i, int *word_nb)
{
	if ((i > 0 && is_space(str[i]) && !is_space(str[i - 1])
			&& !is_redir_pipe(str[i - 1]))
		|| is_redir_pipe(str[i]))
	{
		(*word_nb)++;
		if (i > 0 && is_redir_pipe(str[i]) && !is_redir_pipe(str[i - 1])
			&& !is_space(str[i - 1]))
			(*word_nb)++;
	}
}
