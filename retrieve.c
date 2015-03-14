/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:30:11 by chuang            #+#    #+#             */
/*   Updated: 2015/03/14 17:26:58 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <fcntl.h>

static t_line		*set_line(int nbint, int *tab, t_line *next)
{
	t_line		*tmp;

	if ((tmp = malloc(sizeof(t_line) + 1)) == NULL)
		return (NULL);
	tmp->nbint = nbint;
	tmp->line = tab;
	tmp->next = next;
	return (tmp);
}

int				countheight(t_line *first)
{
	int i;

	i = 0;
	while (first != NULL)
	{
		first =first->next;
		i++;
	}
	return i;
}

int				countlength(t_line *first)
{
	int		i;

	i = 0;
	while (first != NULL)
	{
		if (i < first->nbint)
			i = first->nbint;
		first = first->next;
	}
	return (i);
}

static int				*gnl_int(int fd)
{
	char	*line;
	char	**split;
	int		*tab;
	int		i;

	if(get_next_line(fd, &line) == 0)
		return (NULL);
	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
		i++;
	if (((tab = malloc(sizeof(int*) * i + 1))) == NULL)
		exit (0);
	tab[0] = i;
	i = 0;
	while (i < tab[0])
	{
		tab[i + 1] = ft_atoi(split[i]);
		i++;
	}
	free(split);
	return (tab);
}

t_line			*lst_tabint(char *av)
{
	int			fd;
	int			*tab;
	t_line		*first;
	t_line		*tmp;

	if ((fd = open(av, O_RDONLY)) < 1)
		exit (0);
	if ((tab = gnl_int(fd)) == NULL)
		return (NULL);
	first = set_line(tab[0], &tab[1], NULL);
	tmp = first;
	while ((tab = gnl_int(fd)) != NULL)
	{
		tmp->next = set_line(tab[0], &tab[1], NULL);
		tmp = tmp->next;
	}
	if (close(fd) == -1)
		exit (0);
	return (first);
}
