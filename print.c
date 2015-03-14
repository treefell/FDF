/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:57:46 by chuang            #+#    #+#             */
/*   Updated: 2015/03/14 16:39:24 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>


int		key_hook(int keycode, t_env *e)
{
	if (e == NULL)
		exit (0); //change to something needed
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		ft_print(t_line *first)
{
	t_env *e;

	if ((e = malloc(sizeof(t_env))) == NULL)
		exit (0);
	e->mlx = mlx_init();
	e->first = first;
	e->zheight = 4;
	e->gap = 25;
	e->length = countlength(first) * e->gap * 2;
	e->height = countheight(first) * e->gap * 2;
	e->win = mlx_new_window(e->mlx, e->length, e->height, "flyingcow");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

