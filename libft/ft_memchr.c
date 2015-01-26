/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:57:13 by chuang            #+#    #+#             */
/*   Updated: 2014/11/07 18:32:44 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void *ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*newstr;
	unsigned int	i;

	newstr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (newstr[i] == (unsigned char)c)
			return (&newstr[i]);
		i++;
	}
	return (NULL);
}
