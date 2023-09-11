/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:23 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/11 15:31:45 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	t_minishell		ms;

	(void) argv;
	shell_init(&ms);
	args_check(argc);
	while (1)
	{
		signal_init(prompt_handler);
		ms.prompt = readline(CYAN "minishell> " GREEN);
		if (!ms.prompt)
			break ;
		if (ms.prompt)
			add_history(ms.prompt);
		if (ms.prompt)
		{
			prompt_init(&ms);
				
		}
        // TODO Parse / lexer user input
		
		//! Exec
		builtins(&ms);
		// parser(&ms);

        // Clean up
		free(ms.prompt);
    }
	return (0);
}

void	shell_init(t_minishell *ms)
{
	g_var = 0;
	history_init();
	termios_init();
	ms->tokens_nb = 0;
	ms->format_prompt = 0;
}
