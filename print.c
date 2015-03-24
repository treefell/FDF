/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:57:46 by chuang            #+#    #+#             */
/*   Updated: 2015/03/24 21:02:15 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == KEY_S)
		e->zheight--;
	if (keycode == KEY_W)
		e->zheight++;
	if (keycode == KEY_DOWN)
		e->posy += 10;
	if (keycode == KEY_UP)
		e->posy -= 10;
	if (keycode == KEY_RIGHT)
		e->posx += 10;
	if (keycode == KEY_LEFT)
		e->posx -= 10;
	if (keycode == KEY_MINUS)
		e->gap--;
	if (keycode == KEY_PLUS)
		e->gap++;
	if (keycode == KEY_C)
		set_pal(e);
	if (keycode == KEY_ESC)
		exit(0);
	draw(e);
	mlx_clear_window(e->mlx, e->win);
	expose_hook(e);
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
	e->gap = 10;
	e->length = countlength(first) * e->gap;
	e->height = countheight(first) * e->gap;
	e->size.x = 0.82 * e->length - 0.82 * e->height;
	e->size.y = (0.82 / 2.0) * e->length + (0.82 / 2.0) * e->height;
	e->posx = 0;
	e->posy = 0;
	set_pal(e);
	e->win = mlx_new_window(e->mlx, e->length * 2, e->height * 2, "flyingcow");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
