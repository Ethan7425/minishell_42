/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_suffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:19:49 by etbernar          #+#    #+#             */
/*   Updated: 2023/09/11 13:15:02 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_suffix(const char suffix, va_list args)
{
	int	count;

	count = 0;
	if (suffix == 'c')
		count += (char)ft_put_c(va_arg(args, int));
	if (suffix == 's')
		count += ft_put_s(va_arg(args, char *));
	if (suffix == 'i' || suffix == 'd')
		count += ft_put_i(va_arg(args, int));
	if (suffix == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	if (suffix == 'X' || suffix == 'x')
		count += (char)ft_put_x(va_arg(args, int), suffix);
	if (suffix == 'p')
		count += ft_put_p(va_arg(args, unsigned int));
	if (suffix == '%')
		return (write(1, "%", 1));
	return (count);
}
