/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:14:53 by etbernar          #+#    #+#             */
/*   Updated: 2023/06/09 12:06:55 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_i(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (nb < 0)
	{
		count += ft_put_c('-');
		count += ft_put_i(-nb);
	}
	else if (nb > 9)
	{
		count += ft_put_i(nb / 10);
		count += ft_put_i(nb % 10);
	}
	else
		count += ft_put_c(nb + '0');
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_put_s(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write (1, &str[count], 1);
		count++;
	}
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_put_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_put_i(nb / 10);
		count += ft_put_i(nb % 10);
	}
	else if (nb >= 0 && nb <= 9)
		count += ft_put_c(nb + '0');
	if (count < 0)
		return (-1);
	return (count);
}
