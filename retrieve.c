/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:30:11 by chuang            #+#    #+#             */
/*   Updated: 2015/01/27 17:51:07 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static t_line	set_line(int **line, t_line *next)
{
	t_line	*tmp;
	int		i;

	if (tmp = malloc(sizeof(t_line*) == NULL))
			exit(0);
	i = 0;
	while (line[i])
	{
		tmp->line[i] = line[i];
		i++;
	}
	tmp->line[i] = line[i];
	tmp->next = next;
	return (tmp);
}

static int		**gnretrieve(int fd)
{
	char	**line;
	int		**ret;
	int		i;

	if (line = malloc(sizeof(char**) == NULL))
			exit(0);
	if (i = get_next_line(fd, line) == -1)
		exit(0);
	else if (i == 0)
		return (NULL);
	line = ft_strsplit(*line);
	
		
	if (ret = malloc(sizeof(int**) == NULL))
		exit(0);
	i = 0;
	while (line[i])
	{
		ret[i] = ft_atoi(line[i]);
		ft_getnbr(ret[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

t_line			*ft_tablstint(int fd)
{
	t_line		*first;
	t_line		*tmp;
	t_line		*new;
	int			**tab;

	if (tab = malloc(sizeof(int**) == NULL))
		exit(0);
	if ((tab = gnretrieve(fd)))
	first = set_line(tab, NULL);
	tmp = first;
	while(tab = gnretrieve(fd))
	{
		new = setline(tab, NULL);
		tmp->next = new;
		tmp = new;
	}
	return (first);
}
