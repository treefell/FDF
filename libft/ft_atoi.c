/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:04:00 by chuang            #+#    #+#             */
/*   Updated: 2014/11/08 17:13:59 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

static int		ft_sign(const char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	return (0);
}

int				ft_atoi(char *str)
{
	int		i;
	int		nb;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	nb = ft_strlen(str);
	while (ft_isspace(str[i]) && i < nb)
		i++;
	i += (sign = ft_sign(str[i])) ? 1 : 0;
	while (ft_isdigit(str[i]) && i <= nb)
	{
		res *= (ft_isdigit(str[i])) ? 10 : 1;
		res += str[i] - 48;
		i++;
	}
	res *= (sign != 0) ? sign : 1;
	return (res);
}
