/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:57 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/07 23:01:14 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Set the terminal attributes so that unwanted ^C are not printed
void	termios_init(void)
{
	struct termios	termios;

	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		fatal_error("Error with tcgetattr");
	termios.c_lflag &= ~ECHOCTL;
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		fatal_error("Error with tcgetattr");
}