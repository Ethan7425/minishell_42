/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 08:24:14 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/11 08:34:24 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*tab;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	if (n < len)
		len = n;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
