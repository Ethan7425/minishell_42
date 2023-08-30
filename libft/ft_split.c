/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etbernar <etbernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:53:47 by etbernar          #+#    #+#             */
/*   Updated: 2022/11/04 12:26:59 by etbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_nb(char const *s, char c)
{
	int	i;
	int	count;
	int	ok;

	i = 0;
	count = 0;
	ok = 0;
	while (s[i])
	{
		if (s[i] != c && ok == 0)
		{
			ok = 1;
			count++;
		}
		else if (s[i] == c)
			ok = 0;
		i++;
	}
	return (count);
}

static char	*ft_word_into_tab(char const *s, int start, int end)
{
	int		i;
	char	*tab_str;

	i = 0;
	tab_str = malloc(sizeof(char) * (end - start + 1));
	if (!tab_str)
		return (NULL);
	while (start < end)
	{
		tab_str[i] = s[start];
		start++;
		i++;
	}
	tab_str[i] = '\0';
	return (tab_str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		i_tab;

	i = 0;
	j = 0;
	i_tab = 0;
	tab = malloc(sizeof(char *) * (word_nb(s, c) + 1));
	if (!tab || !s)
		return (NULL);
	while (i_tab < word_nb(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		tab[i_tab] = ft_word_into_tab(s, i, j);
		i = j;
		i_tab++;
	}
	tab[i_tab] = 0;
	return (tab);
}

/*int main()
{
	const char *s = "cou cou";
	printf("%s\n", *ft_split(s, ' '));
}*/