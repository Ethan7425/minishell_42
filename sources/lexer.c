/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:23:19 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/09 12:34:49 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_count_arg(const char *str)
{
	int		i;
	int		nb_word;
	char	cur_quote;

	if (!str)
		return (0);
	nb_word = 0;
	cur_quote = 0;
	i = -1;
	while (str[++i])
	{
	
		update_quote_status(str[i], &cur_quote);	//TODO
		if (!cur_quote)
	
			update_word_count(str, i, &nb_word);	//TODO
	}
	if (!ft_is_space(str[i - 1]) && !ft_is_pipe_or_redirec(str[i - 1]))
		nb_word++;
	return (nb_word);
}

char	*ft_get_next_arg(const char *str, int *start)
{
	int		i;
	char	cur_quote;
	char	*word;

	cur_quote = 0;
	i = *start;
	if (!str || !str[i])
		return (NULL);
	while (ft_is_space(str[i]))
		i++;
	*start = i;
	while (str[i])
	{
		update_quote_status(str[i], &cur_quote); //TODO
		if (!cur_quote)
		{
			word = handle_character(str, i, start); //TODO
			if (word)
				return (word);
		}
		i++;
	}
	return (extract_tokens(str, i, start));
}

char	**ft_lexer(char const *str)
{
	int		i;
	int		nb_word_cpt;
	int		nb_args;
	char	**splited;

	if (!str)
		return (NULL);
	nb_args = ft_count_arg(str);
	splited = malloc((nb_args + 1) * sizeof(char *));
	if (!splited)
		fatal_error("memory allocation error4\n");
	i = 0;
	nb_word_cpt = 0;
	while (nb_word_cpt < nb_args)
	{
		splited[nb_word_cpt] = ft_get_next_arg(str, &i);
		if (!splited[nb_word_cpt])
			return (NULL);
		nb_word_cpt++;
	}
	splited[nb_args] = NULL;
	return (splited);
}