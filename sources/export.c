/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:30:58 by melanieyane       #+#    #+#             */
/*   Updated: 2023/11/02 09:45:00 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//export sans argument affiche toutes les variables d'environnement avec 'declare -x ' devant et la valeur entre "" (mais aussi la variable non-valide ???)
//export avec un ou plusieurs arguments valides les ajoutent dans l'env
//export avec un ou plusieurs arguments invalides n'affiche rien
//export avec une variable qui existe deja, en modifie sa valeur (attention à free et à malloc)

int	is_in_env2(char **env_var, const char *var)
{
	int	i;
	int	j;

	i = 0;
	while (env_var[i])
	{
		j = 0;
		while (env_var[i][j] != '=' && env_var[i][j] != '\0')
			j++;
		if (strncmp(env_var[i], var, j) == 0)
			return (1);
		i ++;
	}
	return (0);
}

void	export_process(char ***env_var, char *var) //pr ajouter la variable dans la liste d'env
{
	int		n_var;
	char	**result;

	n_var = 0;
	while ((*env_var)[n_var])
		n_var++;
	result = malloc(sizeof(char *) * (n_var + 2));
	if (!result)
		return ;
	n_var = 0;
	while ((*env_var)[n_var])
	{
		result[n_var] = strdup((*env_var)[n_var]);
		free((*env_var)[n_var]);
		n_var ++;
	}
	result[n_var] = strdup(var);
	result[n_var + 1] = NULL;
	free(*env_var);
	*env_var = result;
}

int	check_var(char *var) //pr verifier le format de la variable 
{
	int	i;

	if (var[0] == '=')
	{
		printf("export: '%s': not a valid identifier\n", var);
		return (0);
	}
	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (1);
		i ++;
	}
	return (0);
}

//si commence par un '=' retourne "'=salut': not a valid identifier"
//si ne contient pas de '=' ne fait rien
//si contient un '=' et rien apres, l'ajoute

void	print_export(char ***env_var)//pr printer si juste export sans arg
{
	int	i;
	int	j;

	i = 0;
	while ((*env_var)[i])
	{
		printf("declare -x ");
		j = 0;
		while ((*env_var)[i][j] != '=')
		{
			printf("%c", (*env_var)[i][j]);
			j ++;
		}
		printf("\"");
		while ((*env_var)[i][j])
		{
			printf("%c", (*env_var)[i][j]);
			j ++;
		}
		printf("\"\n");
		i ++;
	}
}

int	should_replace(char *var, const char *target)
{
	int	pos;

	pos = 0;
	while (var[pos] != '=')
		pos ++;
	if (strncmp(target, var, pos) == 0
		&& target[pos] == '=')
		return (1);
	return (0);
}

void	ft_export(char ***env_var, char **var)
{
	int	i;
	int	n_var;

	if (var[1] == NULL)
		print_export(env_var);
	i = 1;
	while (var[i])
	{
		if (check_var(var[i]) == 1)
		{
			n_var = 0;
			while ((*env_var)[n_var])
			{
				if (should_replace(var[i], (*env_var)[n_var]) == 1)
				{
					free((*env_var)[n_var]);
					(*env_var)[n_var] = strdup(var[i]);
				}
				n_var++;
			}
			if (is_in_env2(*env_var, var[i]) == 0)
				export_process(env_var, var[i]);
		}
		i++;
	}
}

//check le nbr d'arguments
//si aucun, print export (soit 1 juste export)
//check var pr voir si l'entree est valide
//si valide et check_rep retourne 0, ajouter dans la liste d'env
//si valide et check rep retourne 1, modifier l'entree correspondante dans la liste d'env
//si non valide, return

/*
int	main(void)
{
	char	**env_var;
	int		i;
	char	*argv[] = {"export", "SHELL=blou", "=salut", "salut", "LOGNAME=MELTHEBEST", "melanie=thebest", NULL};

	set_env(&env_var);
	//ft_env(&env_var);
	//printf("\n\n\n");
	ft_export(&env_var, argv);
	printf("\n\n\n");
	ft_env(&env_var);
}
*/