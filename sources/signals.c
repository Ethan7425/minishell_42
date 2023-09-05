/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:25:02 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/05 21:31:08 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	signal_handler(int signum)
{
	if (signum == SIGINT && g_cat == 1)
	{
		ft_putstr_fd("^C \n", 2);
		g_cat = 130;
	}
	else if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_cat = 0;
	}
	if (signum == SIGQUIT && g_cat == 1)
	{
		ft_putstr_fd("^\\Quit: 3\n", 2);
		g_cat = 131;
	}
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_cat = 0;
	}
}

void	signal_init(void)
{
	signal(SIGQUIT, signal_handler);
	signal(SIGINT, signal_handler);
}