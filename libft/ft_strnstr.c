/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:47:58 by chuang            #+#    #+#             */
/*   Updated: 2014/11/07 23:41:27 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t hlen)
{
	size_t			nlen;
	unsigned int	i;

	i = 0;
	nlen = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)hay);
	while (i + nlen <= hlen && hay[i])
	{
		if (ft_strncmp(&hay[i], needle, nlen) == 0)
			return ((char*)&hay[i]);
		i++;
	}
	return (NULL);
}
