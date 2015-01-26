/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:54:13 by chuang            #+#    #+#             */
/*   Updated: 2014/11/09 15:14:25 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static int		ft_count(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*nb;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	i = ft_count(n);
	tmp = n;
	nb = ft_strnew(i);
	if (n < 0)
	{
		tmp *= -1;
		nb[0] = '-';
	}
	while (i > 0 && tmp)
	{
		nb[i - 1] = tmp % 10 + '0';
		tmp /= 10;
		i--;
	}
	nb[0] = (n == 0) ? '0' : nb[0];
	return (nb);
}
