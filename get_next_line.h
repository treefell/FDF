/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:12:26 by chuang            #+#    #+#             */
/*   Updated: 2015/01/23 19:23:24 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# define BUFF_SIZE 8

typedef struct		s_buff
{
	char			buff[BUFF_SIZE + 1];
	size_t			cursor;
	int				size;
	int				fd;
	struct s_buff	*next;
}					t_buff;

int					get_next_line(int const fd, char **line);

#endif
