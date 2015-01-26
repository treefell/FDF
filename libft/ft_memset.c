/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:25:03 by chuang            #+#    #+#             */
/*   Updated: 2014/11/03 15:28:26 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*newb;

	newb = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		newb[i] = (unsigned char)c;
		i++;
	}
	return (newb);
}
