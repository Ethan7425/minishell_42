/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:46:33 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/12 11:49:28 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrdup(char **arr)
{
	int		i;
	char	**arr_copy;

	i = 0;
	while (arr[i])
		i++;
	arr_copy = malloc(sizeof(char *) * i + 1);
	if (!arr_copy)
		return (NULL);
	i = -1;
	while (arr[i])
	{
		arr_copy[i] = ft_strdup(arr[i]);
		if (!arr_copy[i])
		{
			ft_free_char_2d(arr_copy);
			return (NULL);
		}
		i++;
	}
	arr_copy[i] = NULL;
	return (arr_copy);
}
