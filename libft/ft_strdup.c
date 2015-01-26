/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/18 18:37:15 by exam              #+#    #+#             */
/*   Updated: 2014/11/17 14:45:10 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		w;

	w = 0;
	if ((dup = ft_strnew(ft_strlen(src))) == NULL)
		return (NULL);
	while (src[w])
	{
		dup[w] = src[w];
		w++;
	}
	return (dup);
}
