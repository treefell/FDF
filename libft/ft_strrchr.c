/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:56:08 by chuang            #+#    #+#             */
/*   Updated: 2014/11/07 16:06:44 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char *ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = -1;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			j = i;
		i++;
	}
	if (str[i] == (char)c)
		j = i;
	if (j < 0)
		return (NULL);
	return (&str[j]);
}
