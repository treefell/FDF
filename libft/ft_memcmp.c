/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:19:22 by chuang            #+#    #+#             */
/*   Updated: 2014/11/05 15:43:45 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	unsigned char		*news1;
	unsigned char		*news2;

	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	i = 0;
	if (n != 0)
		while (i < n)
		{
			if (news1[i] != news2[i])
				return (news1[i] - news2[i]);
			i++;
		}
	return (0);
}
