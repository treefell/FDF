/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:14:00 by chuang            #+#    #+#             */
/*   Updated: 2015/02/05 18:39:23 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_print(lst_tabint(av[1]));
	}
	else
		ft_putendl("invalid argument");
	return (0);
}
