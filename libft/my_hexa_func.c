/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hexa_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:02:39 by etbernar          #+#    #+#             */
/*   Updated: 2023/06/09 12:07:26 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_x(unsigned int nb, int suffix)
{
	char	*alpha;

	if (suffix == 'x' )
		alpha = "0123456789abcdef";
	else
		alpha = "0123456789ABCDEF";
	return (ft_base16(nb, alpha));
}

unsigned long	ft_put_p(unsigned int nb)
{
	char	*alpha;
	int		count;

	count = 2;
	ft_put_s("0x");
		alpha = "0123456789abcdef";
	return (ft_base16(nb, alpha) + count);
}

int	ft_base16(unsigned int nb, char *alpha)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_base16(nb / 16, alpha);
		count += ft_base16(nb % 16, alpha);
	}
	else
		count += ft_put_c(alpha[nb]);
	if (count < 0)
		return (-1);
	return (count);
}
