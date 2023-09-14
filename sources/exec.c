/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:34:43 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/14 13:22:54 by etbernar         ###   ########.fr       */
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
		echo(token);
		//printf("echo a ete request\n");
	else if (strncmp(token->commands[0], "cd", 3) == 0)
		printf("cd a ete request\n");
		//? cd(token, ms);
	else if (strncmp(token->commands[0], "pwd", 4) == 0)
		printf("pwd a ete request\n");
		//? pwd(token);
	else if (strncmp(token->commands[0], "export", 7) == 0)
		printf("export a ete request\n");
		//? export(token, ms);
	else if (strncmp(token->commands[0], "unset", 6) == 0)
		printf("unset a ete request\n");
		//? unset(token, ms);
	else if (strncmp(token->commands[0], "env", 4) == 0)
		printf("env a ete request\n");
		//? env(ms); myb envp 
	else if (strncmp(token->commands[0], "exit", 4) == 0)
		printf("exit a ete request\n");
		//? our_exit(token);
	
}

// void externals()
// {

// }