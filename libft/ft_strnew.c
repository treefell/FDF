/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 23:24:57 by chuang            #+#    #+#             */
/*   Updated: 2014/11/09 17:20:54 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *new;

	if (!(new = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
