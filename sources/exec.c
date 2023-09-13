/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:34:43 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/13 18:30:21 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executionner(t_token *token, t_minishell *ms)
{
	builtins(token, ms);
}


void	builtins(t_token *token, t_minishell *ms)
{
	ms->a = 0; //! juste pour mute le warning
	if (strncmp(token->commands[0], "echo", 5) == 0)
		printf("echo a ete request\n");
		//TODO
	if (strncmp(token->commands[0], "cd", 3) == 0)
		printf("cd a ete request\n");
		//TODO
	if (strncmp(token->commands[0], "pwd", 4) == 0)
		printf("pwd a ete request\n");
		//TODO
	if (strncmp(token->commands[0], "export", 7) == 0)
		printf("export a ete request\n");
		//TODO
	if (strncmp(token->commands[0], "unset", 6) == 0)
		printf("unset a ete request\n");
		//TODO
	if (strncmp(token->commands[0], "env", 4) == 0)
		printf("env a ete request\n");
		//TODO
	if (strncmp(token->commands[0], "exit", 4) == 0)
		printf("exit a ete request\n");
		//TODO
	
}

// void externals()
// {

// }