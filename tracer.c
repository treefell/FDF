/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 17:40:15 by chuang            #+#    #+#             */
/*   Updated: 2015/04/04 15:22:36 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

t_coord			conv_iso(t_coord p, t_env *e)
{
	t_coord	ret;

	p.z = p.z * e->zheight;
	ret.x = 0.82 * p.x - 0.82 * p.y + (e->length - e->size.x / 2) + e->posx;
	ret.y = -p.z + (0.82 / 2.0)
		* p.x + (0.82 / 2.0) * (p.y) + (e->height - e->size.y / 2) + e->posy;
	ret.z = p.z;
	return (ret);
}

t_coord			setcoord(int x, int y, int z)
{
	t_coord		new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

void			tracerseg(t_coord v1, t_coord v2, t_env *env)
{
	t_coord d;
	t_coord e;
	t_coord s;

	d.x = abs(v2.x - v1.x);
	s.x = v1.x < v2.x ? 1 : -1;
	d.y = abs(v2.y - v1.y);
	s.y = v1.y < v2.y ? 1 : -1;
	e.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (v1.x != v2.x || v1.y != v2.y)
	{
		put_pixel(env, v1, v2);
		e.y = e.x;
		if (e.y > -d.x)
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

void			drawline(t_line *first, t_env *e, int y)
{
	t_coord		p1;
	t_coord		p2;
	int			x;

	x = 0;
	while (x < first->nbint)
	{
		p1 = setcoord(e->gap * (x), e->gap * (y), first->line[x]);
		if (x + 1 < first->nbint)
		{
			p2 = setcoord(e->gap * (x + 1), e->gap * (y), first->line[x + 1]);
			tracerseg(conv_iso(p1, e), conv_iso(p2, e), e);
		}
		if (first->next && x < first->next->nbint)
		{
			p2 = setcoord(e->gap * (x), e->gap * (y + 1), first->next->line[x]);
			tracerseg(conv_iso(p1, e), conv_iso(p2, e), e);
		}
		x++;
	}
}

void			draw(t_env *e)
{
	t_line		*first;
	int			y;

	y = 0;
	first = e->first;
	while (first)
	{
		drawline(first, e, y);
		first = first->next;
		y++;
	}
}
