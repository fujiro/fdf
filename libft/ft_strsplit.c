/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elcarrei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:00:13 by elcarrei          #+#    #+#             */
/*   Updated: 2016/11/27 21:53:10 by elcarrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_split_count(char const *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	if (str[0] != '\0')
		count++;
	return (count);
}

static char		*ft_split_words(char const *str, char c, int *i)
{
	char	*s;
	int		j;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (NULL);
	j = 0;
	while (str[*i] != c && str[*i])
	{
		s[j] = str[*i];
		j++;
		*i = *i + 1;
	}
	s[j] = '\0';
	while (str[*i] == c && str[*i])
		*i = *i + 1;
	return (s);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	words = ft_split_count(str, c);
	if (!str || !c)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(tab) * words + 2)))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < words && str[i])
	{
		tab[j] = ft_split_words(str, c, &i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
