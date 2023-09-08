/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:23 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/08 15:15:45 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int argc, char **argv) 
{
	// Initialization
	(void) argv;
	t_minishell		ms;
	shell_init(&ms);
	args_check(argc);
	history_init();


    while (1) 
	{
		signal_init();
        // Display shell prompt
        	//display_prompt();
		ms.prompt = readline(CYAN "minishell> " RESET_COLOR);
        // Read user input
        	//char *prompt = read_user_input();

        // Add the user input to history
        if (ms.prompt) 
            add_history(ms.prompt);

        // Parse / lexer user input
        	
		// parser(&ms);

        // Check if it's a built-in command
			// if (is_builtin_command()) {
			// 	execute_builtin(command_args);
			// } else {
			// 	 Execute external command
			// }

        // Clean up
        free(ms.prompt);
        	//free(command_args);

        // Check exit condition (e.g., user types "exit")
			// if (should_exit()) 
			// 	break;
        
    }

    // Perform cleanup and exit
    	//cleanup_shell();
    return 0;
}

void	shell_init(t_minishell *ms)
{
	g_var = 0;
	termios_init();
	ms->tokens_nb = 0;
}