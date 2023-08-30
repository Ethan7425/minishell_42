/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:57:42 by etbernar          #+#    #+#             */
/*   Updated: 2023/06/09 12:11:35 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	k;
	char	*str;

	k = 0;
	str = (char *)b;
	while (k < len)
	{
		str[k] = c;
		k++;
	}
	return (str);
}

/*int main () 
{
   char str[50];

   strcpy(str,"bonjour comment ca va");
   puts(str);

   ft_memset(str,'$',1);
   puts(str);
   
   return(0);
}*/