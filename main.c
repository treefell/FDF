/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:14:00 by chuang            #+#    #+#             */
/*   Updated: 2015/01/27 12:49:38 by chuang           ###   ########.fr       */
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
			exit(0);
		}
		//TODO retrieve intel
		ft_print(fd);
		
		if (close(fd) == -1)
		{
			ft_putendl("an error has occur during close");
		exit(0);
		}
	}
	else
		ft_putendl("invalid argument");
}
