/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 18:53:46 by chuang            #+#    #+#             */
/*   Updated: 2015/01/23 18:48:59 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buff	*ft_setbuff(int fd, t_buff *next)
{
	t_buff		*tmp;

	if ((tmp = malloc(sizeof(t_buff))) == NULL)
		return (NULL);
	tmp->next = next;
	tmp->fd = fd;
	tmp->cursor = 1;
	tmp->size = 1;
	return (tmp);
}

static t_buff	*checkfd(t_buff **first, int fd)
{
	t_buff		*tmp;

	if (!first)
	{
		*first = ft_setbuff(fd, NULL);
		return (*first);
	}
	else
	{
		tmp = *first;
		while (tmp && tmp->fd != fd)
			tmp = tmp->next;
		if (!tmp)
		{
			tmp = *first;
			*first = ft_setbuff(fd, tmp);
			return (*first);
		}
	}
	return (tmp);
}

static void		ftjoint(char **line, char *add, int len)
{
	*line = ft_realloc(*line, ft_strlen(*line) + len + 1);
	*line = ft_strncat(*line, add, (size_t)len);
}

static int		findline(t_buff *tmp, char **line)
{
	char		*lstart;
	char		*line_pos;

	lstart = tmp->buff + tmp->cursor;
	if (ft_memchr(lstart, '\n', tmp->size - tmp->cursor))
	{
		line_pos = ft_memchr(lstart, '\n', tmp->size - tmp->cursor);
		ftjoint(line, lstart, line_pos - (tmp->buff + tmp->cursor));
		tmp->cursor = line_pos - tmp->buff + 1;
		return (1);
	}
	else
	{
		ftjoint(line, lstart, tmp->size - tmp->cursor);
		tmp->cursor = tmp->size;
		return (0);
	}
}

int				get_next_line(int const fd, char **line)
{
	static t_buff	*first;
	t_buff			*tmp;

	if (fd < 0 || line == NULL || (*line = ft_strnew(0)) == NULL)
		return (-1);
	tmp = checkfd(&first, fd);
	while (tmp->size > 0)
	{
		if (tmp->cursor >= (size_t)tmp->size)
		{
			tmp->size = read(fd, tmp->buff, BUFF_SIZE);
			if (tmp->size <= 0)
				return (**line != '\0' ? 1 : tmp->size);
			tmp->cursor = 0;
		}
		if (findline(tmp, line))
			return (1);
	}
	return (tmp->size);
}
