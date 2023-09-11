/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:34:43 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/11 13:34:35 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtins(t_minishell *ms)
{
	if (strncmp(ms->prompt, "echo", 5) == 0)
		printf("echo a ete request");
}

// void externals()
// {

// }