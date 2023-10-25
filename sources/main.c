/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:23 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/25 14:00:38 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell		ms;

	(void) argv;
	shell_init(&ms, envp);
	args_check(argc);
	while (1)
	{
		signal_init(prompt_handler);
		ms.prompt = readline(CYAN "minishell> " GREEN);
		if (!ms.prompt)
			break ;
		if (ms.prompt[0])
			add_history(ms.prompt);
		if (syntax_ok(ms.prompt))
		{
			signal_init(exec_handler);
			prompt_init(&ms);
		}
		// Clean up
		free_all(&ms);
	}
	free_all(&ms);
	// ft_free_char_2d(ms);
	return (0);
}

void	shell_init(t_minishell *ms, char **envp)
{
	ms->envp_copy = ft_arrdup(envp);
	g_var = 0;
	history_init();
	termios_init();
	ms->tokens_nb = 0;
	ms->format_prompt = 0;
}
