/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:37:01 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/07 16:11:52 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void args_check(argc)
{
	if(argc > 1)
	{
		print_error( RED "No args except ./minishell" RED);
		exit(1);
	}
}