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

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libgen.h>

#include "libft.h"
#include "shell.h"
#include "keyboard_keys.h"
#include "command_line_termcaps.h"
#include "auto_completion.h"
#include "tools.h"

void		auto_complete(char *line, t_auto_comp *auto_comp, t_info *info)
{
	DIR				*dir;
	char			*last_slash;
	char			*current_dir;
	char			*texte_a_chercher;
	struct dirent	*file_name;

	if (!line)
		return ;
	last_slash = ft_strrchr(line, '/');
	current_dir = get_dirname(line);
	texte_a_chercher = get_basename(line, last_slash);
	if (!(ft_strcmp(texte_a_chercher, "")))
		return (free_dir_basename(current_dir, texte_a_chercher));
	if ((dir = opendir(current_dir)) == NULL)
		return (free_dir_basename(current_dir, texte_a_chercher));
	while ((file_name = readdir(dir)) != NULL)
		print_file(file_name->d_name, texte_a_chercher,\
		auto_comp, current_dir);
	closedir(dir);
	if (auto_comp->list_words)
		auto_comp->list_words->pos = '1';
	free_dir_basename(current_dir, texte_a_chercher);
	integrate_word(info, line, 0);
	next_word(&(info->auto_completion));
}

char		*get_current_word(char *cmd, int pos, int flag)
{
	unsigned int	start;
	char			*tmp;

	if ((ft_isalnum_or_dot(cmd[pos]) || cmd[pos] == '/') && flag)
		return (NULL);
	if (pos != 0 && (cmd[pos] == ' ' || cmd[pos] == '\0') && cmd[pos - 1]\
		&& (ft_isalnum_or_dot(cmd[pos - 1]) || cmd[pos - 1] == '/'))
		pos--;
	if (!(cmd[pos]) || (ft_isalnum_or_dot(cmd[pos] && cmd[pos] != '/')))
		return (NULL);
	start = (unsigned int)pos;
	if (start == 0 && (ft_isalnum_or_dot(cmd[start]) || cmd[start] == '/'))
		return (ft_strsub(cmd, start, 1));
	while (start)
	{
		if (ft_isalnum_or_dot(cmd[start]) || cmd[start] == '/')
			start--;
		else
			break ;
	}
	if (start != 0)
		start++;
	tmp = ft_strsub(cmd, start, (pos - start) + 1);
	return (tmp);
}

void		call_autocomp2(t_info *info)
{
	char	*current_word;

	current_word = get_current_word(info->term->cmd, info->term->pos_c, 1);
	auto_complete(current_word, &(info->auto_completion), info);
	if (current_word)
		ft_strdel(&current_word);
}

void		mot_suivant(t_info *info)
{
	char	*line;

	line = get_current_word(info->term->cmd, info->term->pos_c, 0);
	integrate_word(info, line, 1);
	next_word(&(info->auto_completion));
	if (line)
		ft_strdel(&line);
}

void		call_autocomp(t_info *info)
{
	int		ret;
	long	chr;

	chr = 0;
	call_autocomp2(info);
	if (info->auto_completion.list_words == NULL)
	{
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
