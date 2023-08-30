/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:09:54 by etbernar          #+#    #+#             */
/*   Updated: 2022/10/25 16:24:32 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (void *)s;
	while (i < n)
	{	
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (0);
}

/*int main () {
   const char str[] = "coucouuuuu";
   const char ch = 'u';
   char *res;

   res = ft_memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, res);

   return(0);
}*/