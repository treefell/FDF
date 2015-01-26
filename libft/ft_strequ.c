/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:47:23 by chuang            #+#    #+#             */
/*   Updated: 2014/11/08 17:18:41 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int patate;

	patate = 0;
	while (s1[patate] && s1[patate] == s2[patate])
		patate++;
	if (s1 == s2)
		return (1);
	return (0);
}
