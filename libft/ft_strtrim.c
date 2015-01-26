/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:33:13 by chuang            #+#    #+#             */
/*   Updated: 2014/11/08 17:22:35 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n') ? 1 : 0;
}

static int	ft_ftspace(char const *s)
{
	int i;

	i = 0;
	while (ft_space(s[i]))
		i++;
	if (i >= (int)ft_strlen(s))
		return (0);
	return (i);
}

static int	ft_edspace(char const *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (ft_space(s[i]) == 1)
		i--;
	return (strlen(s) - i - 1);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		frontsp;
	int		endsp;

	frontsp = (ft_ftspace(s) > 0) ? ft_ftspace(s) : 0;
	endsp = (ft_edspace(s) > 0) ? ft_edspace(s) : 0;
	len = strlen(s) - frontsp - endsp;
	if (frontsp + endsp == 0)
		return (ft_strdup(s));
	if (frontsp || endsp)
		return (ft_strsub(s, frontsp, len));
	return (ft_strnew(1));
}
