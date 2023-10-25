/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:30:14 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/25 12:57:33 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Replace the token->commands[0] by the path of cmd if found
// Returns 0 if it succeeds
// Returns MALLOC_ERR in case of a malloc error
// Returns 1 if the command is not found
int	init_cmd_path(t_token *token, char **envp_cpy)
{
	char	*path_str;
	char	**path;

	if (!token->commands || !token->commands[0][0])
		return (0);
	if (is_builtin(token))
	{
		token->builtin = 1;
		return (0);
	}
	if (access(token->commands[0], F_OK) == 0)
	{
		token->valid_cmd = 1;
		return (0);
	}
	path_str = ft_getenv("PATH", envp_cpy);
	if (!path_str)
		return (1);
	path = ft_split(path_str, ':');
	if (!path)
		fatal_error("Error with malloc()");
	if (search_cmd_in_path(path, token) == 0)
		return (0);
	else
		return (1);
}

// Return 0 if the command is found in the path. 
// Set the value of token->commands[0] to the path.
// Return 1 if the command is not found.
// Return MALLOC_ERR if there is a malloc error.
int	search_cmd_in_path(char **path, t_token *token)
{
	int		i;
	char	*tmp_path;
    char    *tmp_path2;

	i = -1;
	while (path[++i])
	{
        tmp_path2 = ft_strjoin(path[i], "/");
        tmp_path = ft_strjoin(tmp_path2, token->commands[0]);
		if (!tmp_path)
			fatal_error("Error with malloc()");
		if (access(tmp_path, F_OK) == 0)
		{
			free(token->commands[0]);
			token->commands[0] = tmp_path;
			token->valid_cmd = 1;
			ft_free_char_2d(path);
			return (0);
		}
		free(tmp_path);
	}
	ft_free_char_2d(path);
	return (1);
}

// Goes through all token to set their paths
void	init_path_tokens(t_token *token, char **envp_cpy)
{
	while (token)
	{
		init_cmd_path(token, envp_cpy);
		token = token->next;
	}
}
