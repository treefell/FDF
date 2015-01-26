/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:35:09 by chuang            #+#    #+#             */
/*   Updated: 2014/11/08 17:20:00 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		poney;
	char	*frais;

	poney = 0;
	if ((frais = (char *)ft_memalloc(strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[poney])
	{
		frais[poney] = f(s[poney]);
		poney++;
	}
	return (frais);
}
