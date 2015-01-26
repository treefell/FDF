/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:14:00 by chuang            #+#    #+#             */
/*   Updated: 2015/01/26 13:29:32 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fnctl.h>
#include "libft.h"

int		main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RONLY)) == -1)
		{
			ft_putendl("An error has occur during open");
			exit();
		}
		//TODO retrieve intel;
		
		if (close(fd) == -1)
		{
			ft_putendl("an error has occur during close");
		exit ();
		}
	}
	else
		ft_putendl("invalid argument");
}
