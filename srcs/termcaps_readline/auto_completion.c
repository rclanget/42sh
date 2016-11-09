/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeguign <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:16:47 by gdeguign          #+#    #+#             */
/*   Updated: 2016/11/09 11:16:49 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define BUFF_SIZE 42
#define BUFFER_SIZE     1024

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include <libgen.h>

#include "auto_completion.h"

/*
info->term->cmd

srcs/termcaps_readline/termcaps_loop.c

srcs/termcaps_readline/termcaps_handle_keyboard.c

srcs/termcaps_readline/keyboard_move_word.c

add_chr

mettre 22 au lieu de 21 dans un des fichier

creer une fction et rajouter une ligne dans le tableau t_key g_key_tab
*/

char	*ft_strdup_spe(const char *s1)
{
	char    *str;
	int     a;

	a = 0;
	str = NULL;
	if (s1 && (str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 2))))
	{
		while (s1[a])
		{
			str[a] = s1[a];
			a++;
		}
		str[a] = '/';
		str[a + 1] = '\0';
		return (str);
	}
	else
		return (NULL);
}

t_dlist		*ajouter_avant(t_dlist *element, char *str, int is_dir)
{
	t_dlist     *nouvel_element;

	nouvel_element = malloc(sizeof(*nouvel_element));
	if (nouvel_element != NULL)
	{
		nouvel_element->pos = '0';
		if (is_dir)
			nouvel_element->str = ft_strdup_spe(str);
		else
			nouvel_element->str = ft_strdup(str);
		nouvel_element->suiv = element;
		//ft_print("lelement courant est %s , le suivant %s\n", nouvel_element->str, nouvel_element->suiv->str);
		return (nouvel_element);
	}
	return (NULL);
}

t_dlist		*cree_liste(char *str, int is_dir)
{
	t_dlist		*racine;

	racine = malloc(sizeof(*racine));
	if (racine != NULL)
	{
		racine->pos = '0';
		racine->suiv = NULL;
		if (is_dir)
			racine->str = ft_strdup_spe(str);
		else
			racine->str = ft_strdup(str);
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

void	print_list_completion(t_dlist *head)
{
	t_dlist *tmp;

	tmp = head;
	if (!head)
		return ;
	ft_putendl("************affichage de la liste*********");
	while (tmp && tmp->suiv != NULL)
	{
		ft_putendl((char*)tmp->str);
		ft_putchar((char)tmp->pos);
		ft_putchar('\n');
		tmp = tmp->suiv;
	}
	ft_putendl((char*)tmp->str);
	ft_putchar((char)tmp->pos);
	ft_putchar('\n');
	tmp = tmp->suiv;
	ft_putendl("************fin        affichage de la liste************");
}

int		is_directory(const char *my_path, char *key)
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

void	print_file(char *key, char *line, t_auto_comp *auto_c, char *cu_dir)
{
	int		is_dir;

	is_dir = 0;
	if (ft_strcmp(key, ".") == 0 || ft_strcmp(key, "..") == 0)
		return ;
	if (!(ft_strncmp(key, line, ft_strlen(line))))
	{
		if (is_directory(cu_dir, key))
			is_dir = 1;
			//printf("%s\n", key);
		if (!(auto_c->list_words))
		{
			auto_c->list_words = cree_liste(key, is_dir);
		}
		else
			auto_c->list_words = \
		ajouter_avant(auto_c->list_words, key, is_dir);
	}
}

char	*ft_strsplit_spe(char *line, char c)
{
	char	*dir_name;
	char	*tmp;

	dir_name = ft_strdup(line);
	tmp = ft_strrchr(line, c);
	if (*tmp)
		*tmp = '\0';
	return (dir_name);
}

char	*get_dir_from_string(char *line)
{
	char	*current_dir;

	current_dir = NULL;
	if (!(ft_strchr(line, '/')) || line[ft_strlen(line) - 1] == '/')
	{
		current_dir = (char*)malloc(sizeof(char) * 2);
		current_dir[0] = '.';
		current_dir[1] = '\0';
	}
	else
		current_dir = ft_strsplit_spe(line, '/');
	return (current_dir);
}

void	fin_auto_completion(t_auto_comp *auto_completion)
{
	vider_liste(auto_completion->list_words);
	auto_completion->list_words = NULL;
}

char	*word_display(t_dlist *head)
{
	t_dlist *tmp;

	tmp = head;
	if (!head)
		return (NULL);
	while (tmp)
	{
		if (tmp->pos == '1')
			return (tmp->str);
		tmp = tmp->suiv;
	}
	return (NULL);
}

void	next_word(t_auto_comp *auto_completion)
{
	t_dlist	*ptr;

	ptr = auto_completion->list_words;
	if (!ptr || (ptr->suiv == NULL))
		return ;
	while (ptr->pos != '1')
		ptr = ptr->suiv;
	ptr->pos = '0';
	if (ptr->suiv)
		ptr->suiv->pos = '1';
	else
		auto_completion->list_words->pos = '1';
}

void	auto_complete(char *line, t_auto_comp *auto_completion)
{
	DIR				*dir;
	char			*current_dir;
	char			*texte_a_chercher;
	struct dirent	*file_name;

	current_dir = dirname(line);
	texte_a_chercher = basename(line);
	printf("affichage de current_dir[%s]\n", current_dir);
	printf("affichage de texte_a_chercher[%s]\n", texte_a_chercher);
	if ((dir = opendir(current_dir)) == NULL)
	{
		printf("%s\n", "impossible d'ouvrir le dossir courant");
		return ;
	}
	while ((file_name = readdir(dir)) != NULL)
		print_file(file_name->d_name, texte_a_chercher,\
		auto_completion, current_dir);
	closedir(dir);
	if (auto_completion->list_words)
		auto_completion->list_words->pos = '1';
	print_list_completion(auto_completion->list_words);
	next_word(auto_completion);
	ft_putendl(word_display(auto_completion->list_words));
	fin_auto_completion(auto_completion);
}

/*
int		main(void)
{
	char		*line;
	//char		*retour;
	t_auto_comp	auto_completion;


	auto_completion.flag = 0;
	auto_completion.list_words = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl("");
		//retour = 
		auto_complete(line, &auto_completion);
		free(line);
		ft_putendl("");
	}
	return (0);
}
*/
