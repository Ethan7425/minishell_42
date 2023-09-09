/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:25:02 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/09 09:55:27 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	signal_handler(int signum)
// {
// 	if (signum == SIGINT && g_var == 1)
// 	{
// 		ft_putstr_fd("^C \n", 2);
// 		g_var = 130;
// 	}
// 	else if (signum == SIGINT)
// 	{
// 		write(1, "\n", 1);
// 		rl_replace_line("", 0);
// 		rl_on_new_line();
// 		rl_redisplay();
// 		g_var = 0;
// 	}
// 	if (signum == SIGQUIT && g_var == 1)
// 	{
// 		ft_putstr_fd("^\\Quit: 3\n", 2);
// 		g_var = 131;
// 	}
// 	else if (signum == SIGQUIT)
// 	{
// 		rl_on_new_line();
// 		rl_redisplay();
// 		g_var = 0;
// 	}
// }

// void	signal_init(void)
// {
// 	signal(SIGQUIT, signal_handler);
// 	signal(SIGINT, signal_handler);
// }

void	signal_init(void (*signal_handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	prompt_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_var = 1;
	}
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	exec_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "^C\n", 3);
		rl_replace_line("", 0);
		rl_on_new_line();
		g_var = 130;
	}
	if (sig == SIGQUIT)
	{
		write(1, "^\\Quit: 3\n", 10);
		rl_replace_line("", 0);
		rl_on_new_line();
		g_var = 131;
	}
}
