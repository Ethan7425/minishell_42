/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:48:06 by etbernar          #+#    #+#             */
/*   Updated: 2023/10/25 13:02:12 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	replace_env_var(char **input, int start, int end, char *env_var)
{
	int		env_var_len;
	int		input_len;
	int		new_len;
	char	*new_arg;
	char	*original_input;

	original_input = *input;
	env_var_len = ft_strlen(env_var);
	input_len = ft_strlen(*input);
	new_len = input_len - (end - start) + env_var_len;
	new_arg = malloc(sizeof(char) * (new_len + 1));
	if (!new_arg)
		fatal_error("memory allocation error");
	new_arg = ft_memcpy(new_arg, *input, start - 1);
	new_arg[start - 1] = '\0';
	ft_strlcat(new_arg, env_var, new_len + 1);
	ft_strlcat(new_arg, *input + end, new_len + 1);
	free(original_input);
	*input = new_arg;
	return (start + env_var_len - 1);
}

char	*ft_get_env_name(char *arg, int *i, int env_start_ind)
{
	char	*env_name;

	if (!arg)
		return (NULL);
	if (arg[*i] != '?')
	{
		while (ft_isalnum(arg[*i]) || arg[*i] == '_' || arg[*i] == '-')
			(*i)++;
	}
	else
		(*i)++;
	env_name = ft_strndup(arg + env_start_ind, *i - env_start_ind);
	if (!env_name)
		fatal_error("memory allocation error");
	return (env_name);
}

char	*process_env_var(char *arg, char **envp_copy)
{
	int		i;
	char	quote;

	quote = 0;
	i = 0;
	while (arg && arg[i])
	{
		quote_status(arg[i], &quote);
		if (quote != '\'' && arg[i] == '$')
		{
			i++;
			i = handle_env_var(&arg, envp_copy, i);
		}
		else
			i++;
	}
	return (arg);
}

int	handle_env_var(char **arg, char **envp_copy, int i)
{
	int		env_start_ind;
	char	*env_name;
	char	*env_value;

	if (ft_isalnum((*arg)[i]) || (*arg)[i] == '_' || (*arg)[i] == '?')
	{
		env_start_ind = i;
		env_name = ft_get_env_name((*arg), &i, env_start_ind);
		env_value = ft_getenv(env_name, envp_copy);
		i = replace_env_var(&(*arg), env_start_ind, i, env_value);
		free(env_name);
	}
	return (i);
}

char	**expander(char **line_elem, char **envp_copy)
{
	int		i;

	i = 0;
	while (line_elem && line_elem[i])
	{	
		line_elem[i] = process_env_var(line_elem[i], envp_copy);
		line_elem[i] = rm_quotes(line_elem[i]);
		i++;
	}
	return (line_elem);
}

