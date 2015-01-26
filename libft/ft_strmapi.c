/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:33:04 by chuang            #+#    #+#             */
/*   Updated: 2014/11/08 17:20:14 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cpy;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((cpy = (char *)ft_memalloc(strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		cpy[i] = f(i, s[i]);
		i++;
	}
	return (cpy);
}
