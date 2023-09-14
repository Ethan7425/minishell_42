/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:31:30 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/14 10:33:31 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_minishell *ms)
{
	if (ms->prompt)
	{
		free(ms->prompt);
		ms->prompt = NULL;
	}
	if (ms->format_prompt)
	{
		ft_free_char_2d(ms->format_prompt);
		ms->format_prompt = NULL;
	}
	if (ms->token)
	{
		token_free(ms->token);
		ms->tokens_nb = 0;
		ms->token = NULL;
	}
}


