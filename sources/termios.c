/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:10:57 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/11 13:42:21 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Set the terminal attributes so that unwanted ^C are not printed
void	termios_init(void)
{
	struct termios	termios;

	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		fatal_error("Error tcgetattr");
	termios.c_lflag &= ~ECHOCTL;
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		fatal_error("Error tcgetattr");
}
