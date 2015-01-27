/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:40:15 by chuang            #+#    #+#             */
/*   Updated: 2015/01/27 17:52:43 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	tracerseg(t_coord v1, t_coord v2, void *mlx, void *win)
{
	t_coord d;
	t_coord e;
	t_coord s;

	d.x = abs(v2.x - v1.x);
	s.x = v1.x < v2.x ? 1 : -1;
	d.y = abs(v2.y - v1.y);
	s.y = v1.y < v2.y ? 1 : -1;
	e.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (v1.x == v2.x && v1.y == v2.y)
	{
		mlx_pixel_put(mlx, win, v1.x, v1.y, 0xFF0000);
		e.y = e.x;
		if (e2 > -d.x)
		{
			e.x -= d.y;
			v1.x += s.x;
		}
		if (e.y < d.y)
		{
			e.x += d.x;
			v1.y += s.y;
		}
	}
}

void	draw(t_env *e, int fd)
{
	t_line		*first;
	t_coord		p1;
	t_coord		p2;

	p1.y = 0;
	first = ft_tablstint(fd);
	while (first)
	{
		p1.x = 0;
		while (first[p1.x])
		{
			p1.z = first[p1.x];
			if (first[/*p2 = */p1.x + 1])
			{
				p2.x = p1.x + 1;
				p2.y = p1.y;
				p2.z = first[p2.x];
				tracerseg(p1, p2, e->mlx, e->win);
			}
			if (first->next && first->next[p1.x])
			{
				p2.x = p1.x;
				p2.y = p1.y + 1;
				p2.z = first->next[p2.x];
				tracerseg(p1, p2, e->mlx, e->win);
			}
			p1.x++;
		}
		first = first->next;
		p1.y++;
	}
}

