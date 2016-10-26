/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_magicquote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:09:32 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/26 22:22:50 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "execution.h"
#include "alias_struct.h"
#include "get_next_line.h"
#include "shell.h"
#include "tools.h"

#include <fcntl.h>

#define MQ_FILE O_RDWR | O_TRUNC | O_CREAT
#define MQ_FILENAME "/tmp/magicquote"

static void		free_list(t_word *list)
{
	if (list)
	{
		free_list(list->next);
		free(list->word);
		free(list);
	}
}

static char		*get_file_content()
{
	int		fd;
	char	*tmp;
	char	*line;
	char	*content;

	line = NULL;
	content = NULL;
	if ((fd = open(MQ_FILENAME, O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		return line;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strjoin_custom(content, " ");
		free (content);
		content = tmp;
		tmp = ft_strjoin_custom(content, line);
		ft_free_them_all(2, content, line);
		content = tmp;
		line = NULL;
	}
	close(fd);
	return (content);
}

char			*process_magicquote(t_info *info, char *cmd)
{
	int			fdp[2];
	pid_t		pid;
	int			fd;

	pipe(fdp);
	if (!cmd || (fd = open(MQ_FILENAME, MQ_FILE)) == -1)
		return (NULL);
	if (!(pid = fork()))
	{
		dup2(fdp[1], 1), close(fdp[0]);
		ft_putendl(cmd);
		exit(0);
	}
	dup2(fdp[0], 0); close(fdp[1]);
	dup2(fd, 1); close(fd);
	wait(0);
	execution_motor(info, self_node(info), 1);
	return (get_file_content());
}

char			*apply_magicquote(t_info *info, char *str)
{
	t_word		*words;
	char		*tmp;

	tmp = NULL;
	if ((words = get_magicquotelist(str)))
	{
		treat_magicquote(info, words);
		tmp = make_sentence(words);
		free_list(words);
	}
	return (tmp);
}
