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
**condition pour deux ligne du dessous
affichage de current_dir[.]
affichage de texte_a_chercher[]


**coller le path dans la liste de mot


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
	t_dlist     *nouvel_element;

	nouvel_element = malloc(sizeof(*nouvel_element));
	if (nouvel_element != NULL)
	{
		nouvel_element->pos = '0';
		if (is_dir)
			nouvel_element->str = add_path_to_str(str, is_dir, cu_dir);
		else
			nouvel_element->str = add_path_to_str(str, is_dir, cu_dir);
		nouvel_element->suiv = elem;
		//ft_print("lelement courant est %s , le suivant %s\n", nouvel_element->str, nouvel_element->suiv->str);
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
			auto_c->list_words = cree_liste(key, is_dir, cu_dir);
		}
		else
			auto_c->list_words = \
		ajouter_avant(auto_c->list_words, key, is_dir, cu_dir);
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

char	*get_dirname(char *line)
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


char	*get_basename(char *line, char *slash)
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
	char			*last_slash;
	char			*current_dir;
	char			*texte_a_chercher;
	struct dirent	*file_name;

	if (!line)
		return ;
	last_slash = ft_strrchr(line, '/');
	//printf("affichage de line[%s]\n", line);
	current_dir = get_dirname(line);
	texte_a_chercher = get_basename(line, last_slash);
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
	free(current_dir);
	free(texte_a_chercher);
	integrate_word(info, line, 0);
	next_word(&(info->auto_completion));
	//print_list_completion(auto_completion->list_words);
}

#include <stdio.h>

char	*get_current_word(char *cmd, int pos, int flag)
{
	unsigned int	start;
	char 			*tmp;

	if ((ft_isalnum(cmd[pos]) || cmd[pos] == '/') && flag)
	{
		//printf("%s\n", "+++++ici 1 ++++++");
		return (NULL);
	}
	if (pos != 0 && (cmd[pos] == ' ' || cmd[pos] == '\0') && cmd[pos - 1]\
		&& (ft_isalnum(cmd[pos - 1]) || cmd[pos - 1] == '/'))
	{
		//printf("%s\n", "+++++ par la ++++++");
		pos--;
	}
	if (!(cmd[pos]) || (ft_isalnum(cmd[pos] && cmd[pos] != '/')))
	{
		//printf("%s\n", "+++++ici 2 ++++++");
		return (NULL);
	}
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
	tmp = ft_strsub(cmd, start, (pos - start) + 1);
	//printf("affich de TMP [%s]\n", tmp);
	return (tmp);
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
