/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:36:29 by derivederac       #+#    #+#             */
/*   Updated: 2023/06/12 11:24:02 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	first_;
	size_t	last_;

	first_ = 0;
	last_ = ft_strlen(s1);
	while (s1[first_] && is_in_set(s1[first_], set))
		first_++;
	while (last_ > first_ && is_in_set(s1[last_ - 1], set))
		last_--;
	trimmed = malloc(sizeof(char) * (last_ - first_ + 1));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (first_ < last_)
		trimmed[i++] = s1[first_++];
	trimmed[i] = 0;
	return (trimmed);
}

/*int main()
{
    const char *s;
    s = "123 coucou123";
    printf("%s\n", ft_strtrim(s, "123"));
}*/