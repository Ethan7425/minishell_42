/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:23 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/06 16:09:00 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


// int main(int argc, char **argv, char **envp)
// {
// 	if (argc == 1)
// 		write(1, "c", 1);
// }

int main() 
{
	t_minishell		ms;
    // Initialization
    	//shell_init();
	history_init();

    while (1) 
	{
		signal_init();
        // Display shell prompt
        	//display_prompt();
		ms.prompt = readline(CYAN "minishell> " CYAN);
        // Read user input
        	//char *prompt = read_user_input();

        // Add the user input to history
        if (ms.prompt) 
            add_history(ms.prompt);

        // Parse user input
        	//char **command_args = parse_input(prompt);
		parser(&ms);

        // Check if it's a built-in command
			// if (is_builtin_command(command_args[0])) {
			// 	execute_builtin(command_args);
			// } else {
			// 	// Execute external command
			// 	execute_external_command(command_args);
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
