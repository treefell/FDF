/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:53:15 by chuang            #+#    #+#             */
/*   Updated: 2015/03/26 15:51:10 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"
# include "key_define.h"

typedef struct		s_line
{
	int				nbint;
	int				*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
}					t_coord;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_line			*first;
	t_coord			size;
	int				posx;
	int				posy;
	int				length;
	int				height;
	int				gap;
	int				zheight;
	int				col[4];
}					t_env;

t_line				*lst_tabint(char *av);
int					countline(t_line *first);
void				draw(t_env *e);
void				set_pal(t_env *e);
void				put_pixel(t_env *e, t_coord v1, t_coord v2);
int					ft_print(t_line *first);
int					countlength(t_line *first);
int					countheight(t_line *first);
t_coord				conv_iso(t_coord p, t_env *e);
#endif
