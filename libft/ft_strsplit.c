/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:29:58 by chuang            #+#    #+#             */
/*   Updated: 2015/02/04 17:56:46 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_char(char comp, char csplit)
{
	if (comp == csplit)
		return (1);
	return (0);
}

static int		count_sizewtf(char const *str, char csplit)
{
	if (*str == 0)
		return (2);
	if (!is_char(*str, csplit) && is_char(*(str + 1), csplit))
		return (1 + count_sizewtf(str + 1, csplit));
	return (count_sizewtf(str + 1, csplit));
}

static int		count_wordsize(int p, char const *str, char csplit)
{
	int i;

	i = 0;
	while (str[p + i] && !is_char(str[p + i], csplit))
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char csplit)
{
	char	**tab;
	int		i;
	int		wordsize;
	int		nbword;

	tab = malloc(sizeof(char *) * count_sizewtf(s, csplit));
	i = 0;
	nbword = 0;
	while (s[i])
		if (!is_char(s[i], csplit))
		{
			wordsize = count_wordsize(i, s, csplit);
			tab[nbword] = ft_strsub(s, i, wordsize);
			nbword++;
			i += wordsize;
		}
		else
			i++;
	tab[nbword] = NULL;
	return (tab);
}
