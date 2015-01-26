/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 22:46:36 by chuang            #+#    #+#             */
/*   Updated: 2014/11/12 13:14:56 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int		i;
	int					nb;
	int					j;

	if (ft_memchr(dest, '\0', size) == NULL)
		return (size + ft_strlen(src));
	j = 0;
	i = ft_strlen(dest);
	nb = size - i;
	while (src[j] && j < nb - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + ft_strlen(src));
}
