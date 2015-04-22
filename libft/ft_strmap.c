/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:35:09 by chuang            #+#    #+#             */
/*   Updated: 2015/04/22 15:29:41 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		poney;
	char	*frais;

	poney = 0;
	if ((frais = (char *)ft_memalloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[poney])
	{
		frais[poney] = f(s[poney]);
		poney++;
	}
	return (frais);
}
