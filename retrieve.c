/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:30:11 by chuang            #+#    #+#             */
/*   Updated: 2015/01/26 14:55:36 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_line	set_line(int **line, t_line *next)
{
	t_line	*tmp;

	if (tmp = malloc(sizeof(t_line*) == NULL))
			exit ();
	tmp->line = line;
	tmp->next = next;
	return (tmp);
}

static int		**gnretrieve(int fd)
{
	char	**line;
	int		**ret;
	int		i;

	if (line = malloc(sizeof(char**) == NULL))
			exit();
	if (i = get_next_line(fd, line) == -1)
		exit ();
	else if (i == 0)
		return (NULL);
	line = ft_strsplit(*line);
	
		
	if (ret = malloc(sizeof(int**) == NULL))
		exit ();
	i = 0;
	while (line[i])
	{
		ret[i] = ft_atoi(line[i]);
		i++;
	}
	return (ret);
}

t_buff		*ft_lsttabint(int fd)
{
	t_line		*first;
	t_line		*tmp;
	t_line		*new;
	int			**tab;

	if (tab = malloc(sizeof(int**) == NULL))
		exit ();
	if ((tab = gnretrieve))
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
