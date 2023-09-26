/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:04:55 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/26 09:13:04 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	echo(t_token *token)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (token->commands[i] == NULL)
	{
		printf("\n");
		return ;
	}
	if (strncmp(token->commands[i], "-n", 2) == 0)
	{
		i++;
		flag = 1;
	}
	if (token->commands[i] != NULL)
	{
		printf("%s", token->commands[i++]);
		while (token->commands[i])
			printf(" %s", token->commands[i++]);
	}
	if (flag == 0)
		printf("\n");
}

// int	main(void)
// {
// 	char	*argv[] = {"echo", "Hello World", NULL};
// 	char	*argvn[] = {"echo", "-n", "Hello World", NULL};
// 	char	*argv_justecho[] = {"echo", NULL};
// 	char	*argv_test[] = {"echo", "Hello World", "-n", NULL};

// 	echo(argvn);
// 	echo(argv);
// 	echo(argv_justecho);
// 	 echo(argv_test);
// 	return (0);
// }
