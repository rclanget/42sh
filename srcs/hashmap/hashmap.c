/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <gdeguign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:51:22 by gdeguign          #+#    #+#             */
/*   Updated: 2017/01/04 16:17:58 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include "hashmap.h"
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

#define BUFF_PWD 256

void		ecrire_hashmap(t_hashmap *hashmap, char *key, char *val)
{
	char			*tmp;
	char			*tmp2;
	unsigned int	hash_value;

	tmp = ft_strjoin(val, "/");
	tmp2 = ft_strjoin(tmp, key);
	if ((access(tmp2, X_OK)) != -1)
	{
		if (!hashmap || !hashmap->map ||
			(ft_strcmp(key, ".") == 0 || ft_strcmp(key, "..") == 0))
			;
		else
		{
			hash_value = jenkins_one_at_a_time_hash(key, ft_strlen(key));
			if (hashmap->map[hash_value] == NULL)
			{
				hashmap->map[hash_value] = ft_strdup(tmp2);
				hashmap->size++;
			}
		}
	}
	ft_free_them_all(2, &tmp, &tmp2);
}

void		liste_fichier(t_hashmap *map, DIR *dir, char *pwd)
{
	struct dirent	*file_name;

	file_name = NULL;
	while ((file_name = readdir(dir)) != NULL)
		ecrire_hashmap(map, file_name->d_name, pwd);
}

void		ouverture_dossier(int i, char **tab_path, t_hashmap *map, DIR *dir)
{
	while (tab_path && tab_path[i])
	{
		if ((dir = opendir(tab_path[i])) == NULL)
		{
			i++;
			continue ;
		}
		liste_fichier(map, dir, tab_path[i]);
		if (closedir(dir) == -1)
		{
			ft_print("%s\n", "echec closedir");
			break ;
		}
		i++;
	}
}

t_hashmap	*creer_hashmap(char *path, t_hashmap *map)
{
	char	**tab_path;
	int		i;
	DIR		*dir;

	i = 0;
	dir = NULL;
	if (!path || (ft_strlen(path) == 0))
	{
		path = change_path();
	}
	tab_path = ft_strsplit(path, ':');
	ouverture_dossier(i, tab_path, map, dir);
	ft_strdel(&path);
	free_tab(tab_path);
	return (map);
}

t_hashmap	*pre_creer_hashmap(char *path, t_hashmap *hashmap)
{
	int				i;
	int				h_size;

	i = 0;
	h_size = HASHMAP_SIZE;
	if (!hashmap)
		hashmap = (t_hashmap*)malloc(sizeof(t_hashmap));
	hashmap->size = 0;
	hashmap->map = NULL;
	hashmap->map = (char**)ft_memalloc((h_size + 1) * sizeof(char*));
	if (hashmap->map == NULL)
	{
		ft_print("%s\n", "echec malloc hashmap");
		return (0);
	}
	while (i < h_size)
	{
		hashmap->map[i] = NULL;
		i++;
	}
	hashmap = creer_hashmap(path, hashmap);
	return (hashmap);
}
