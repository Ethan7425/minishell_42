/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:38:08 by etbernar          #+#    #+#             */
/*   Updated: 2023/06/09 09:25:12 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char	*g;
	const char	*p;
	size_t		i;

	i = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (*str != '\0' && len > 0)
	{
		g = str;
		p = to_find;
		i = len;
		while (*p != '\0' && *g == *p && i--)
		{
			g++;
			p++;
		}
		if (*p == '\0')
			return ((char *)str);
		str++;
		--len;
	}
	return (0);
}
/*int	main()
{
	const char char1 [100] = "abcdefghijkl";
	const char char2 [100] = "b";
	printf ("%s", ft_strnstr(char1,char2, 2));
}*/