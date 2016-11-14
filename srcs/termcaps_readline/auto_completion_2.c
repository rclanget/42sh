/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion_2.c                                :+:      :+:    :+:   */
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

char		*add_path_to_str_2(char *str, int is_dir, char *cu_dir)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	tmp = ft_strjoin(cu_dir, "/");
	if (is_dir)
		tmp2 = ft_strdup_spe(str);
	else
		tmp2 = ft_strdup(str);
	tmp3 = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (tmp3);
}

char		*add_path_to_str(char *str, int is_dir, char *cu_dir)
{
	if (ft_strcmp(cu_dir, ".") == 0)
	{
		if (is_dir)
			return (ft_strdup_spe(str));
		else
			return (ft_strdup(str));
	}
	if (is_dir)
		return (add_path_to_str_2(str, is_dir, cu_dir));
	return (add_path_to_str_2(str, is_dir, cu_dir));
}

t_dlist		*ajouter_avant(t_dlist *elem, char *str, int is_dir, char *cu_dir)
{
	t_dlist		*nouvel_element;

	nouvel_element = malloc(sizeof(*nouvel_element));
	if (nouvel_element != NULL)
	{
		nouvel_element->pos = '0';
		if (is_dir)
			nouvel_element->str = add_path_to_str(str, is_dir, cu_dir);
		else
			nouvel_element->str = add_path_to_str(str, is_dir, cu_dir);
		nouvel_element->suiv = elem;
		return (nouvel_element);
	}
	return (NULL);
}

t_dlist		*cree_liste(char *str, int is_dir, char *cu_dir)
{
	t_dlist		*racine;

	racine = malloc(sizeof(*racine));
	if (racine != NULL)
	{
		racine->pos = '0';
		racine->suiv = NULL;
		if (is_dir)
			racine->str = add_path_to_str(str, is_dir, cu_dir);
		else
			racine->str = add_path_to_str(str, is_dir, cu_dir);
	}
	return (racine);
}

void		vider_liste(t_dlist *head_ref)
{
	t_dlist		*current;
	t_dlist		*next;

	current = head_ref;
	while (current != NULL)
	{
		next = current->suiv;
		ft_strdel(&current->str);
		free(current);
		current = next;
	}
}
