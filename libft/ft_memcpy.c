/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:48:12 by chuang            #+#    #+#             */
/*   Updated: 2014/11/07 18:05:33 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*newdst;
	unsigned char	*newsrc;

	newdst = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		i++;
	}
	return (newdst);
}
