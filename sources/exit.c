/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:44:07 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/12 13:26:28 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* attention remplacer atoi par ft_atoi */

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i ++;
		else
			return (0);
	}
	return (1);
}

void	ft_exit(t_token *token)
{
	if (token->commands[1] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	else if (is_numeric(token->commands[1]) == 1)
	{
		printf("exit\n");
		exit(ft_atoi(token->commands[1]));
	}
	else
	{
		printf("exit\n");
		printf("numeric argument required\n");
		exit(255);
	}
}

/*
int	main(void)
{
	char	*str[2];

	str[0] = "exit";
	str[1] = "a";
	ft_exit(str);
}
*/

// to print the last exit status 'echo $?'  