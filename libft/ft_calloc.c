/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:05:16 by etbernar          #+#    #+#             */
/*   Updated: 2022/11/04 11:16:57 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tab;
	unsigned long	i;

	i = 0;
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	while (count * size > i)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
