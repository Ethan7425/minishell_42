/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:36:23 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/05 14:38:41 by etbernar         ###   ########.fr       */
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
	//t_minishell		ms;
    // Initialization
    	//shell_init();
    rl_clear_history();
    rl_on_new_line();
    while (1) 
	{
        // Display shell prompt
        	//display_prompt();
		char *prompt = readline(CYAN "mimishell> " CYAN);
        // Read user input
        	//char *prompt = read_user_input();

        // Add the user input to history
        if (prompt && *prompt) 
            add_history(prompt);

        // Parse user input
        	//char **command_args = parse_input(prompt);

        // Check if it's a built-in command
			// if (is_builtin_command(command_args[0])) {
			// 	execute_builtin(command_args);
			// } else {
			// 	// Execute external command
			// 	execute_external_command(command_args);
			// }

        // Clean up
        free(prompt);
        	//free(command_args);

        // Check exit condition (e.g., user types "exit")
			// if (should_exit()) 
			// 	break;
        
    }

    // Perform cleanup and exit
    	//cleanup_shell();
    return 0;
}
