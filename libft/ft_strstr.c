/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:22:12 by chuang            #+#    #+#             */
/*   Updated: 2014/11/07 15:55:15 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *s1, const char *s2)
{
	int				i;
	int				j;
	char			*news1;

	i = 0;
	news1 = (char *)s1;
	if (s2[0] == '\0')
		return (news1);
	while (news1[i])
	{
		j = 0;
		while (s2[j] == news1[i + j])
		{
			if (s2[j + 1] == '\0')
				return (&news1[i]);
			if (news1[i + j] == '\0')
				return (NULL);
			j++;
		}
		i++;
	}
	return (NULL);
}
