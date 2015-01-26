/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:26:18 by chuang            #+#    #+#             */
/*   Updated: 2014/11/08 17:19:07 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	if ((cpy = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		cpy[i + j] = s2[j];
		j++;
	}
	cpy[i + j] = '\0';
	return (cpy);
}
