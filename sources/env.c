/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:11:33 by myanez-p          #+#    #+#             */
/*   Updated: 2023/10/25 12:19:27 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* attention à remplacer strdup par ft_strdup */

void	set_env(char ***env_var)
{
	extern char	**environ;
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (environ[count] != NULL)
		count ++;
	*env_var = malloc(sizeof(char *) * (count + 1));
	while (environ[i] != NULL)
	{
		(*env_var)[i] = ft_strdup(environ[i]);
		i ++;
	}
	(*env_var)[i] = NULL;
}

void	ft_env(t_minishell *ms)
{
	int	i;

	i = 0;
	while (ms->envp_copy[i] != NULL)
	{
		printf("%s\n", ms->envp_copy[i]);
		i ++;
	}
}











char	*ft_getenv(const char *name, char **envp_copy)
{
	int			i;
	int			len;

	if (!valid_name(name) && ft_memcmp(name, "?\0", 2))
		return (NULL);
	if (!ft_memcmp(name, "?\0", 2))
		return (ft_itoa(g_var));
	len = ft_strlen(name);
	i = -1;
	while (envp_copy[++i])
	{
		if (!ft_strncmp(envp_copy[i], name, len) && envp_copy[i][len] == '=')
			return (ft_strchr(envp_copy[i], '=') + 1);
	}
	return (NULL);
}

bool	valid_name(const char *name)
{
	if (!name
		|| (!ft_isalpha(*name) && *name != '_')
		|| !ft_strlen(name))
		return (false);
	name++;
	while (*name)
	{
		if (!ft_isalnum(*name) && *name != '_')
			return (false);
		name++;
	}
	return (true);
}