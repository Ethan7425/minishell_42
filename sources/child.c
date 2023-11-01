/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:02:07 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/31 18:01:54 by etbernar         ###   ########.fr       */
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

void	make_child(t_token *token, t_minishell *ms)
{
	while (token)
	{
		token->pid = fork();
		if (token->pid < 0)
			fatal_error("Error with fork()");
		if (token->pid == 0)
		{
			check_infile(token, ms);
			check_cmd_validity(token, ms);
			set_dups(token);
			clean_up(token, ms);
			if (token->builtin)
				builtins(token, ms);
			else
				external(token, ms);
		}
		token = token->next;
	}
}

void	check_infile(t_token *token, t_minishell *ms)
{
	if (!token->redir.valid_infile)
	{
		printf("minishell: %s: No such file or directory 1\n",
			token->redir.infile);
		clean_up(token, ms);
		exit(1);
	}
}

void	check_cmd_validity(t_token *token, t_minishell *ms)
{
	if (!token->valid_cmd && !token->builtin)
	{
		if (ft_find_index_env("PATH", ms->envp_copy) == -1)
			printf("minishell: %s: No such file or directory \n",
				token->commands[0]);
		else
			printf("minishell: %s: command not found\n", token->commands[0]);
		exit(127);
	}
}

void	set_dups(t_token *token)
{
	if (dup2(token->redir.infile_fd, STDIN_FILENO) < 0)
		fatal_error("Error with dup2() when redirecting stdin");
	if (dup2(token->redir.outfile_fd, STDOUT_FILENO) < 0)
		fatal_error("Error with dup2() when redirecting stdout");
}

void	clean_up(t_token *token, t_minishell *ms)
{
	ms->a = 0;
	close_redir_fd(token);
}



//! Temp 
int	ft_find_index_env(const char *name, char **envp_copy)
{
	int			i;
	int			len;

	if (!name || !(*envp_copy))
		return (-1);
	len = ft_strlen(name);
	i = -1;
	while (envp_copy[++i])
	{
		if (!ft_strncmp(envp_copy[i], name, len) && envp_copy[i][len] == '=')
			return (i);
	}
	return (-1);
}