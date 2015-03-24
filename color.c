/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 18:42:14 by chuang            #+#    #+#             */
/*   Updated: 2015/03/24 21:42:28 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void		set_pal(t_env *e)
{
	if (!e->col[0] || e->col[0] == 0x996600)
	{
		e->col[0] = 0x009900;
		e->col[1] = 0x0099FF;
		e->col[2] = 0xFFFFFF;
	}
	else if (e->col[0] == 0x009900)
	{
		e->col[0] = 0xFF0000;
		e->col[1] = 0x9900FF;
		e->col[2] = 0xFFFF00;
	}
	else
	{
		e->col[0] = 0x996600 ;
		e->col[1] = 0xCCFFFF ;
		e->col[2] = 0x999999 ;
	}
	
}

void		put_pixel(t_env *e, t_coord p, t_coord p0)
{
	int		col;

	if ( p0.z < p.z)
		p.z = p0.z;
	col = e->col[0];
	if (p.z < 0)
		col = e->col[1];
	else if (p.z > 10)
		col = e->col[2];
	mlx_pixel_put(e->mlx, e->win, p.x, p.y, col);
}
