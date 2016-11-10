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
//#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libgen.h>

#include "libft.h"
#include "keyboard_keys.h"
#include "command_line_termcaps.h"
#include "auto_completion.h"

/*
info->term->cmd

srcs/termcaps_readline/termcaps_loop.c

srcs/termcaps_readline/termcaps_handle_keyboard.c

srcs/termcaps_readline/keyboard_move_word.c

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
		//ft_putchar((char)tmp->pos);
		//ft_putchar('\n');
		tmp = tmp->suiv;
	}
	ft_putendl((char*)tmp->str);
	// ft_putchar((char)tmp->pos);
	// ft_putchar('\n');
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

void	integrate_word(t_info *info, char *line, int first_time)
{
	char	*tmp;
	int		i;

	tmp = &info->term->cmd[info->term->pos_c];
	i = 0;
	while (*tmp && (*tmp == '/' || ft_isalnum(*tmp)))
	{
		tmp++;
		i++;
	}
	tmp = ft_strdup(tmp);
	(void)info;
	(void)i;
	// printf("affichage de tmp [%s]\n", tmp);
	// sleep(1);
	char *word;
	word = word_display(info->auto_completion.list_words);
	if (!word)
		return ;
	//printf("****affichage de word [%s]\n", word);
	//sleep(1);
	ft_print("%s", info->term->capa->str_cd);
	//move_cursor(term->capa, term->pos_c , ft_strlen(term->prompt), 0);`

	ft_strcpy(&info->term->cmd[info->term->pos_c - ft_strlen(line) + first_time], word);
	ft_strcpy(&info->term->cmd[info->term->pos_c - ft_strlen(line) + ft_strlen(word) + first_time], tmp);
	move_cursor(info->term->capa, info->term->pos_c, ft_strlen(info->term->prompt), 0);
    ft_print("%s", info->term->cmd);
    move_cursor(info->term->capa, ft_strlen(info->term->cmd), ft_strlen(info->term->prompt), info->term->pos_c);
    free(tmp);
}

void	auto_complete(char *line, t_auto_comp *auto_completion, t_info *info)
{
	DIR				*dir;
	char			*current_dir;
	char			*texte_a_chercher;
	struct dirent	*file_name;

	if (!line)
		return ;
	current_dir = dirname(line);
	texte_a_chercher = basename(line);
	//printf("affichage de current_dir[%s]\n", current_dir);
	//printf("affichage de texte_a_chercher[%s]\n", texte_a_chercher);
	if ((dir = opendir(current_dir)) == NULL)
	{
		//printf("%s\n", "impossible d'ouvrir le dossir courant");
		return ;
	}
	while ((file_name = readdir(dir)) != NULL)
		print_file(file_name->d_name, texte_a_chercher,\
		auto_completion, current_dir);
	closedir(dir);
	if (auto_completion->list_words)
		auto_completion->list_words->pos = '1';
	integrate_word(info, line, 0);
	next_word(&(info->auto_completion));
	//print_list_completion(auto_completion->list_words);
}

#include <stdio.h>

char	*get_current_word(char *cmd, int pos, int flag)
{
	unsigned int	start;

	if ((ft_isalnum(cmd[pos]) || cmd[pos] == '/') && flag)
		return (NULL);
	if (pos != 0 && (cmd[pos] == ' ' || cmd[pos] == '\0') && cmd[pos - 1]\
		&& (ft_isalnum(cmd[pos - 1]) || cmd[pos - 1] == '/'))
		pos--;
	if (!(cmd[pos]) || !(ft_isalnum(cmd[pos]) || cmd[pos] == '/'))
		return (NULL);
	start = (unsigned int)pos;
	if (start == 0 && (ft_isalnum(cmd[start]) || cmd[start] == '/'))
		return (ft_strsub(cmd, start, 1));
	while (start)
	{
		if (ft_isalnum(cmd[start]) || cmd[start] == '/')
			start--;
		else
			break;
	}
	if (start != 0)
		start++;
	//char * ft_strsub(char const *s, unsigned int start, en);
	// printf("%s\n", "");
	// printf("affichage de start[%u]\n", start);
	// printf("affichage de pos[%d]\n", pos);
	// printf("%s\n", "");
	return (ft_strsub(cmd, start, (pos - start) +  1));
}

void			call_autocomp2(t_info *info)
{
	char	*current_word;

	//printf("\naffichage de info->term->cmd[%s]\n", info->term->cmd);
	current_word = get_current_word(info->term->cmd, info->term->pos_c, 1);
	//printf("affichage de current_word[%s]\n", current_word);
	auto_complete(current_word, &(info->auto_completion), info);
	if (current_word)
		free(current_word);
	//ft_putendl("fonction d'autocomp appelee");

}

void			mot_suivant(t_info *info)
{
	char	*line;

	line = get_current_word(info->term->cmd, info->term->pos_c, 0);
	integrate_word(info, line, 1);
	next_word(&(info->auto_completion));
}

void			call_autocomp(t_info *info)
{
	int 		ret;
	long 		chr;

	chr = 0;
	call_autocomp2(info);
	if (info->auto_completion.list_words == NULL)
	{
		//printf("%s\n", "Jesuislaaaaaaaaaaaa");
		fin_auto_completion(&info->auto_completion);
		return ;
	}
	while ((ret = read(0, &chr, sizeof(chr))) > 0)
    {
        if (chr == TAB)
        	mot_suivant(info);
        else
        	break ;
    }
    fin_auto_completion(&info->auto_completion);
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
