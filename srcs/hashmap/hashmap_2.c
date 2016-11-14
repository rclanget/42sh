/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:51:43 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/14 14:51:47 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "hashmap.h"
#include "hashmap_struct.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

unsigned int	jenkins_one_at_a_time_hash(char *key, size_t len)
{
	unsigned int	hash;
	unsigned int	i;

	i = 0;
	hash = 0;
	while (i < len)
	{
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash % HASHMAP_SIZE);
}

int				check_access(char *str)
{
	if (access(str, F_OK) == -1)
	{
		ft_putendl("cd: no such file or directory: ");
		return (0);
	}
	else if (access(str, X_OK) == -1)
	{
		ft_putendl("cd: permission denied: ");
		return (0);
	}
	return (1);
}

char			*lire_hashmap(t_hashmap *hashmap, char *key)
{
	return (hashmap->map[jenkins_one_at_a_time_hash(key, ft_strlen(key))]);
}

char			*change_path(void)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = NULL;
	tmp2 = NULL;
	tmp3 = NULL;
	line = NULL;
	fd = open("/private/etc/paths", O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strjoin_custom(line, ":");
		ft_strdel(&line);
		tmp2 = tmp3;
		tmp3 = ft_strjoin_custom(tmp2, tmp);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
	}
	return (tmp3);
}

void			print_hashmap(t_hashmap *hashmap)
{
	unsigned int	i;
	char			**map;

	i = 0;
	map = hashmap->map;
	if (!map)
		return ;
	while (i < HASHMAP_SIZE)
	{
		if (map[i] != NULL)
			ft_putendl(map[i]);
		i++;
	}
}
