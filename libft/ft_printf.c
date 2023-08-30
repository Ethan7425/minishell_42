/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:43:19 by etbernar          #+#    #+#             */
/*   Updated: 2023/06/09 12:11:19 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *suffix, ...)
{
	int		pos;
	int		count;
	va_list	args;	

	count = 0;
	pos = 0;
	va_start(args, suffix);
	while (suffix[pos])
	{
		if (suffix[pos] == '%')
		{
			pos++;
			count += check_suffix(suffix[pos], args);
		}
		else
			count += ft_put_c(suffix[pos]);
		pos++;
	}
	va_end (args);
	if (!count)
		return (0);
	return (count);
}

/* int main()
{
	printf("1: hello my name is %s and i am %d old\n", "ethan", 20);
    printf("2: hello my name is %s and i am %d old\n", "ethan", 20);
    printf("1.1: %d\n", printf("something random.\n"));
    printf("2.1: %d\n", ft_printf("something random.\n"));

	printf("COUNT EHTAN: %d\n", ft_printf("SALUT %s %c %u","salut",'e', 42)); 
	printf("COUNT ORDI: %d\n", printf("SALUT %s %c %u","salut",'e', 42)); 


} */
/*
int main()
{
    char *str = NULL;
    int adrss = -87;
    unsigned int unbr = 354687524;
    // char c = '%';


    printf("==========================\n");
    printf("test avec des char\n");
    printf("==========================\n");

    printf("ft nbr: %d\n",ft_printf("%c%c%c\n", '0', 0, '1'));
    printf("sy nbr: %d\n",printf("%c%c%c\n", '0', 0, '1'));

    printf("==========================\n");
    printf("test avec des string\n");
    printf("==========================\n");

    printf("ft nbr: %d\n",ft_printf("%s\n", str));
    printf("sy nbr: %d\n",printf("%s\n", str));

    printf("==========================\n");
    printf("test avec des Int\n");
    printf("==========================\n");

    printf("ft nbr : %d\n",ft_printf("%d\n", adrss));
    printf("sy nbr: %d\n",printf("%d\n", adrss));

    printf("==========================\n");
    printf("test avec des Unsigned Int\n");
    printf("==========================\n");

    printf("ft nbr: %d\n",ft_printf("%u\n", unbr));
    printf("sy nbr: %d\n",printf("%u\n", unbr));


    printf("==========================\n");
    printf("test avec des Hexadecimal\n");
    printf("==========================\n");

    printf("ft nbr: %d\n",ft_printf("%x\n", adrss));
    printf("sy nbr: %d\n",printf("%x\n", adrss));

    printf("==========================\n");
    printf("test avec des Adresse\n");
    printf("==========================\n");

    printf("ft nbr: %d\n",ft_printf("%p\n", &adrss));
    printf("sy nbr: %d\n",printf("%p\n", &adrss));

}*/