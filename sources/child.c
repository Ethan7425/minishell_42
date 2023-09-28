/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:02:07 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/28 10:02:59 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	childable(t_token *token)
{
	if (!token->commands)
		return (1);
	if (ft_strncmp(token->commands[0], "exit", 5) == 0
		|| ft_strncmp(token->commands[0], "cd", 3) == 0
		|| ft_strncmp(token->commands[0], "unset", 6) == 0)
	{
		if (token->next == NULL)
			return (0);
	}
	else if (ft_strncmp(token->commands[0], "export", 7) == 0)
	{
		if (token->commands[1])
			return (0);
	}
	return (1);
}
