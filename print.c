/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:57:46 by chuang            #+#    #+#             */
/*   Updated: 2015/03/19 17:03:49 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int		expose_hook(t_env *e)
{
	draw(e);
	return(0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 115)
		e->zheight--;
	if (keycode == 119)
		e->zheight++;
	if (keycode == 65364)
		e->posy++;
	if (keycode == 65362)
		e->posy--;
	if(keycode == 65363)
		e->posx++;
	if(keycode == 65361)
		e->posx--;
	if(keycode == 65453)
		e->gap--;
	if(keycode ==65451)
		e->gap++;
	if (keycode == 65307)
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
	e->size.y = /*countzheight * e->zheight +*/ (0.82/2.0)
		* e->length + (0.82/2.0) * e->height;
	e->posx = 0;
	e->posy = 0;
	e->win = mlx_new_window(e->mlx, e->length * 2, e->height * 2, "flyingcow");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

