/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:14:29 by myanez-p          #+#    #+#             */
/*   Updated: 2023/11/02 09:50:54 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//chdir change current working directory, causes the named directory to become the current directory
//retourne 0 si c'est tout ok, retourne -1 si problème

//getcwd copies the absolute path name of the current working directory into buf and returns a pointer to it

//only with a relative or an absolute path


// void	ft_cd(t_token *token, t_minishell *ms)

void	ft_cd(char ***env_var, char **str)
{
	char	old_wd[4096];
	char	target_wd[4096];
	char	**path;

	path = ms->envp_copy;
	getcwd(old_wd, sizeof(old_wd));
	if (str[1] == NULL)
		return ;
	if (chdir(str[1]) != 0)
	{
		perror("cd");
	}
	else if (getcwd(target_wd, sizeof(target_wd)) != NULL)
	{
		path[0] = strdup("export");
		path[1] = ft_strjoin("PWD=", target_wd);
		path[2] = ft_strjoin("OLDPWD=", old_wd);
		path[3] = NULL;
		ft_export(env_var, path);
	}
}
