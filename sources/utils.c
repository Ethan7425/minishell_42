/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:37:01 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/09 12:33:50 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void args_check(argc)
{
	if(argc > 1)
	{
		print_error( RED "No args except ./minishell" RED);
		exit(1);
	}
}

int	ft_is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_is_pipe(int c)
{
	return (c == '|');
}

int	ft_is_redirec(int c)
{
	return (c == '<' || c == '>');
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
			ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
		*start = i;
	}
	else
	{
		token = ft_strndup(str + *start, 1);
		if (!token)
			ft_fatal_error("memory allocation error\n", E_ERROR_MALLOC);
		*start = i + 1;
	}
	return (token);
}
