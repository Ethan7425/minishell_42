/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:38:52 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/11 15:46:13 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	prompt_init(t_minishell *ms)
{
	ms->format_prompt = lexer(ms->prompt);
	printf("lexer input is %c", ms->format_prompt[1][0]);
}
