/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:20:36 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/13 14:55:11 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_str_arr_cat(char **str_arr, const char *new_str)
{
	int		len_str_arr;
	char	**new_str_arr;
	int		i;

	len_str_arr = 0;
	i = 0;
	if (!new_str)
		return (str_arr);
	while (str_arr && str_arr[len_str_arr])
		len_str_arr++;
	new_str_arr = malloc((len_str_arr + 2) * sizeof(char *));
	if (!new_str_arr)
		fatal_error("malloc error\n");
	while (i < len_str_arr)
	{
		new_str_arr[i] = ft_strdup(str_arr[i]);
		if (!new_str_arr[i])
			fatal_error("malloc error\n");
		i++;
	}
	new_str_arr[len_str_arr] = ft_strdup(new_str);
	if (!new_str_arr[len_str_arr])
		fatal_error("malloc error\n");
	new_str_arr[len_str_arr + 1] = NULL;
	ft_free_char_2d(str_arr);
	return (new_str_arr);
}
