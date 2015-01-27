/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:53:15 by chuang            #+#    #+#             */
/*   Updated: 2015/01/27 17:00:37 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H


typedef struct		s_line
{
	int				**line;
	struct s_buff	*next;
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
}					t_env;
#endif
