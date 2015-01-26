/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:53:18 by chuang            #+#    #+#             */
/*   Updated: 2015/01/23 17:26:41 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t n)
{
	void		*dst;
	size_t		i;

	if ((dst = malloc(n)) == NULL)
		return (NULL);
	i = 0;
	dst = ft_memcpy(dst, src, n);
	free(src);
	return (dst);
}
