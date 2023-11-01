/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:34:43 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/31 17:58:58 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executionner(t_token *token, t_minishell *ms)
{
	init_path_tokens(ms->token, ms->envp_copy);
	redir_init(token);
	if (!childable(token))
		builtins(token, ms);

	else
		make_child(token, ms);
	clean_up(token, ms);
	wait_children(token);
		//printf("child");
		
}

void	builtins(t_token *token, t_minishell *ms)
{
	ms->a = 0; //! juste pour mute le warning
	if (strncmp(token->commands[0], "echo", 5) == 0)
		echo(token);
	else if (strncmp(token->commands[0], "pwd", 4) == 0)
		printf("pwd a ete request\n");
		//? pwd(token);
	else if (strncmp(token->commands[0], "export", 7) == 0)
		printf("export a ete request\n");
		//? export(token, ms);
	else if (strncmp(token->commands[0], "env", 4) == 0)
		ft_env(ms);
		//printf("env a ete request\n");


	else if (strncmp(token->commands[0], "cd", 3) == 0)
		printf("cd a ete request\n");
		//? cd(token, ms);
	else if (strncmp(token->commands[0], "unset", 6) == 0)
		printf("unset a ete request\n");
		//? unset(token, ms);		
	else if (strncmp(token->commands[0], "exit", 4) == 0)
		printf("exit a ete request\n");
		// ft_exit(token);
}

int	external(t_token *token, t_minishell *ms)
{
	if (token->commands)
	{
		execve(token->commands[0], token->commands, ms->envp_copy);
		printf("minishell: %s: command not found\n", token->commands[0]);
	}
	exit(127);
}

void	wait_children(t_token *token)
{
	int	status;

	while (token)
	{
		waitpid(token->pid, &status, 0);
		if (WIFEXITED(status))
		{
			status = WEXITSTATUS(status);
			g_var = status;
		}
		token = token->next;
	}
}