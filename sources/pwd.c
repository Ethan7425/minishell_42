/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:59:58 by melanieyane       #+#    #+#             */
/*   Updated: 2023/11/02 09:29:20 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//the maximum path length on Unix-based systems is typically 4096 characters
//perror looks up the value of the global variable errno and translates it into an error message

void	ft_pwd(void)
{
	char	cwd[4096];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
		perror("getcwd");
}

/*
int	main(void)
{
	ft_pwd();
}
*/