/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:39:13 by chuang            #+#    #+#             */
/*   Updated: 2015/01/23 19:35:55 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *ele))
{
	t_list		*first;
	t_list		*new;

	if (!lst || !f)
		return (NULL);
	if ((new = ft_lstnew(NULL, 0)) == NULL)
		return (NULL);
	new = f(lst);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		if ((new->next = ft_lstnew(NULL, 0)) == NULL)
			return (NULL);
		new->next = f(lst);
		new = new->next;
	}
	return (first);
}
