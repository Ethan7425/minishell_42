/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:27:22 by etbernar          #+#    #+#             */
/*   Updated: 2022/11/04 12:36:15 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	str = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			str = (char *) &s[i];
		i++;
	}
	if (s[i] == (char) c)
		str = (char *) &s[i];
	return (str);
}

/*int main () 
{
	const char str[] = "abacadefgahij";	
	const char ch = 'a';
	char *res;
	printf("%d\n", ft_strlen(str));
	res = ft_strrchr(str, ch);

	printf("Str apres dernier %c = %s\n", ch, res);
   
	return(0);
}*/