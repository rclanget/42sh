/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:16:47 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/09 11:16:49 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libgen.h>

#include "libft.h"
#include "keyboard_keys.h"
#include "command_line_termcaps.h"
#include "auto_completion.h"
#include "tools.h"

void		print_list_completion(t_dlist *head)
{
	t_dlist *tmp;

	tmp = head;
	if (!head)
		return ;
	ft_putendl("************affichage de la liste*********");
	while (tmp && tmp->suiv != NULL)
	{
		ft_putendl((char*)tmp->str);
		tmp = tmp->suiv;
	}
	ft_putendl((char*)tmp->str);
	tmp = tmp->suiv;
	ft_putendl("************fin        affichage de la liste************");
}

int			is_directory(const char *my_path, char *key)
{
	char		*path;
	char		*tmp;
	struct stat	statbuf;

	tmp = ft_strjoin("/", key);
	path = ft_strjoin(my_path, tmp);
	if (stat(path, &statbuf) != 0)
	{
		free(path);
		free(tmp);
		return (0);
	}
	free(path);
	free(tmp);
	return (S_ISDIR(statbuf.st_mode));
}

void		print_file(char *key, char *line, t_auto_comp *auto_c, char *cu_dir)
{
	int		is_dir;

	is_dir = 0;
	if (ft_strcmp(key, ".") == 0 || ft_strcmp(key, "..") == 0)
		return ;
	if (!(ft_strncmp(key, line, ft_strlen(line))))
	{
		if (is_directory(cu_dir, key))
			is_dir = 1;
		if (!(auto_c->list_words))
		{
			auto_c->list_words = cree_liste(key, is_dir, cu_dir);
		}
		else
			auto_c->list_words = \
		ajouter_avant(auto_c->list_words, key, is_dir, cu_dir);
	}
}

char		*get_dirname(char *line)
{
	char	*current_dir;
	char	*tmp;

	current_dir = NULL;
	if (!(ft_strrchr(line, '/')) || line[ft_strlen(line) - 1] == '/')
	{
		current_dir = (char*)malloc(sizeof(char) * 2);
		current_dir[0] = '.';
		current_dir[1] = '\0';
	}
	else
	{
		current_dir = ft_strdup(line);
		tmp = ft_strrchr(current_dir, '/');
		if (tmp)
			*tmp = '\0';
	}
	return (current_dir);
}

char		*get_basename(char *line, char *slash)
{
	char	*basename;

	if (!slash)
		return (ft_strdup(line));
	else if (slash + 1)
		return (ft_strdup(slash + 1));
	basename = (char*)malloc(sizeof(char));
	basename[0] = '\0';
	return (basename);
}
