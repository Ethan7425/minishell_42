/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 08:46:40 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/12 08:48:25 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool open_quotes(char *str)
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