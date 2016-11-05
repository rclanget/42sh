#include <stdio.h>

# define BUFF_SIZE 42
# define BUFFER_SIZE     1024

# include <stdlib.h>
#include <unistd.h>
# include "libft.h"
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include <libgen.h>

#include "auto_completion.h"


int get_next_line(int fd, char **line);
/*
info->term->cmd

srcs/termcaps_readline/termcaps_loop.c

srcs/termcaps_readline/termcaps_handle_keyboard.c

srcs/termcaps_readline/keyboard_move_word.c

add_chr

mettre 22 au lieu de 21 dans un des fichier

creer une fction et rajouter une ligne dans le tableau t_key g_key_tab
*/
int		is_directory(const char *my_path, char *key)
{
	char	*path;
	char	*tmp;
	
	tmp = ft_strjoin("/", key);
	path = ft_strjoin(my_path, tmp);
	struct stat statbuf;
	if (stat(path, &statbuf) != 0)
	{
		free(path);
		free(tmp);
		return 0;
	}
	free(path);
	free(tmp);
	return S_ISDIR(statbuf.st_mode);
}

void	print_file(char *key, char *line, t_auto_comp *auto_completion, char *current_dir)
{
	int		is_dir;

	is_dir = 0;
	if (ft_strcmp(key, ".") == 0 || ft_strcmp(key, "..") == 0)
		return ;
	if (!(ft_strncmp(key, line, ft_strlen(line))))
	{
		if (is_directory(current_dir, key))
			is_dir = 1;
		//printf("%s\n", key);
		if (!(auto_completion->list_words))
		{
			auto_completion->list_words = cree_liste(key, is_dir);
		}
		else
			auto_completion->list_words = ajouter_avant(auto_completion->list_words, key, is_dir);
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

char	*auto_complete(char *line, t_auto_comp *auto_completion)
{
	DIR*			dir;
	char			*current_dir;
	char			*texte_a_chercher;
	struct dirent* file_name;


	current_dir = dirname(line);
	texte_a_chercher = basename(line);
	printf("affichage de current_dir[%s]\n", current_dir);
	printf("affichage de texte_a_chercher[%s]\n", texte_a_chercher);
	if ((dir = opendir(current_dir)) == NULL)
	{
		printf("%s\n", "impossible d'ouvrir le dossir courant");
		return (NULL);
	}
	while ((file_name = readdir(dir)) != NULL)
		print_file(file_name->d_name, texte_a_chercher, auto_completion, current_dir);
	closedir(dir);
	if (auto_completion->list_words)
		auto_completion->list_words->pos = '1';
	print_list_completion(auto_completion->list_words);
	next_word(auto_completion);
	ft_putendl(word_display(auto_completion->list_words));
	fin_auto_completion(auto_completion);
}

int		main(void)
{
	char		*line;
	char		*retour;
	t_auto_comp	auto_completion;


	auto_completion.flag = 0;
	auto_completion.list_words = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_putendl("");
		retour = auto_complete(line, &auto_completion);
		free(line);
		ft_putendl("");
	}
	return (0);
}
