/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_completion_4.c                                :+:      :+:    :+:   */
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

void		fin_auto_completion(t_auto_comp *auto_completion)
{
	vider_liste(auto_completion->list_words);
	auto_completion->list_words = NULL;
}

char		*word_display(t_dlist *head)
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

void		next_word(t_auto_comp *auto_completion)
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

void		integrate_word(t_info *info, char *line, int first_time)
{
	char	*tmp;
	char	*word;

	tmp = &info->term->cmd[info->term->pos_c];
	while (*tmp && (*tmp == '/' || ft_isalnum_or_dot(*tmp)))
		tmp++;
	tmp = ft_strdup(tmp);
	(void)info;
	word = word_display(info->auto_completion.list_words);
	if (!word)
		return (ft_strdel(&tmp));
	ft_print("%s", info->term->capa->str_cd);
	ft_strcpy(&info->term->cmd[info->term->pos_c - ft_strlen(line) +\
	first_time], word);
	ft_strcpy(&info->term->cmd[info->term->pos_c - ft_strlen(line) +\
	ft_strlen(word) + first_time], tmp);
	move_cursor(info->term->capa, info->term->pos_c,\
	ft_strlen(info->term->prompt), 0);
	ft_print("%s", info->term->cmd);
	move_cursor(info->term->capa, ft_strlen(info->term->cmd),\
	ft_strlen(info->term->prompt), info->term->pos_c);
	ft_strdel(&tmp);
}

void		free_dir_basename(char *dir, char *file_name)
{
	ft_strdel(&dir);
	ft_strdel(&file_name);
}
