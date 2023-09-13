/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:34:43 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/13 11:54:12 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtins(t_minishell *ms)
{
	//token->token_id = 0; //! juste pour mute le warning
	if (strncmp(ms->prompt, "echo", 5) == 0)
		printf("echo a ete request\n");
		//TODO
	if (strncmp(ms->prompt, "cd", 3) == 0)
		printf("cd a ete request\n");
		//TODO
	if (strncmp(ms->prompt, "pwd", 4) == 0)
		printf("pwd a ete request\n");
		//TODO
	if (strncmp(ms->prompt, "export", 7) == 0)
		printf("export a ete request\n");
		//TODO
	if (strncmp(ms->prompt, "unset", 6) == 0)
		printf("unset a ete request\n");
		//TODO
	if (strncmp(ms->prompt, "env", 4) == 0)
		printf("env a ete request\n");
		//TODO
	if (strncmp(ms->prompt, "exit", 4) == 0)
		printf("exit a ete request\n");
		//TODO
	
}

// void externals()
// {

// }