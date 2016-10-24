#include "tools.h"
#include "hashmap.h"
#include "hashmap_struct.h"
#include "libft.h"
#include "get_next_line.h"

#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

#define BUFF_PWD 256

char		*lire_hashmap(t_hashmap *map, char *key)
{
	t_hashmap	*temp;

	temp = map;
	if (map == NULL)
		return (NULL);
	while (temp && (ft_strcmp(temp->key, key)) != 0)
			temp = temp->next;
	if ((ft_strcmp(temp->key, key)) == 0)
		return (temp->value);
	return (NULL);
}

t_hashmap	*ecrire_hashmap(t_hashmap *map, char *key, char *val)
{
	t_hashmap *new;
	t_hashmap *temp;
	char	*tmp;

	tmp = NULL;
	temp = map;
	if (ft_strcmp(key, ".") == 0 || ft_strcmp(key, "..") == 0)
		return (map);
	new = malloc(sizeof(t_hashmap));
	new->next = NULL;
	tmp = ft_strjoin("/", key);
	new->value = ft_strjoin(val, tmp);
	free(tmp);
	new->key = ft_strdup(key);
	if (!map)
		return (new);
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (map);
}

int			check_access(char *str)
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


t_hashmap	*liste_fichier(t_hashmap *map, DIR*	dir, char *pwd)
{
	struct dirent* file_name;
	// char	*pwd;

	// pwd = NULL;
	// pwd = getcwd(pwd, BUFF_PWD);
	file_name = NULL;
	while ((file_name = readdir(dir)) != NULL)
		map = ecrire_hashmap(map, file_name->d_name, pwd);
	// ft_strdel(&pwd);
	return (map);
}

char		*change_path(void)
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

t_hashmap	*creer_hashmap(char *path, t_hashmap *map)
{
	char	**tab_path;
	int		i;
	DIR*	dir;
	// char	*pwd;

	// pwd = NULL;
	// pwd = getcwd(pwd, BUFF_PWD);
	i = 0;
	dir = NULL;
	if (!path)
		path = change_path();
	tab_path = ft_strsplit(path, ':');
	while (tab_path[i])
	{
		// chdir(tab_path[i]);
		if ((dir = opendir(tab_path[i])) == NULL)
		{
			i++;
			continue ;
		}
		map = liste_fichier(map, dir, tab_path[i]);
		if (closedir(dir) == -1)
		{
			ft_print("%s\n", "echec closedir");
			exit(-1);
		}
		i++;
	}
	ft_strdel(&path);
	// chdir(pwd);
	// ft_strdel(&pwd);
	free_tab(tab_path);
	return (map);
}

void		print_hashmap(t_hashmap *map)
{
	t_hashmap	*temp;

	temp = map;
	if (!temp)
		ft_print("%s\n", "pas de hashmap");
	while (temp)
	{
		ft_print("key : %s\n", temp->key);
		ft_print("value : %s\n", temp->value);
		temp = temp->next;
	}
}
