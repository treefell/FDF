/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:59:39 by chuang            #+#    #+#             */
/*   Updated: 2015/01/21 15:19:34 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*newsrc;
	unsigned char	*newdst;
	int				i;

	i = 0;
	newsrc = (unsigned char *)src;
	newdst = (unsigned char *)dst;
	if (dst > src)
	{
		i = ft_strlen(src);
		i = (size_t)i > len ? len : i;
		i--;
		while (i >= 0)
		{
			newdst[i] = newsrc[i];
			i--;
		}
	}
	else
		newdst = (unsigned char *)ft_memcpy(newdst, newsrc, len);
	return (newdst);
}
