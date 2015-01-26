/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:17:53 by chuang            #+#    #+#             */
/*   Updated: 2014/11/09 17:45:10 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*cpy;
	unsigned int	i;

	if ((cpy = (char *)ft_strnew(len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	return (cpy);
}
