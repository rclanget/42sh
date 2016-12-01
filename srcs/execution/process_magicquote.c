/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_magicquote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 22:09:32 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/02 00:20:04 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "execution.h"
#include "alias_struct.h"
#include "get_next_line.h"
#include "shell.h"
#include "tools.h"

#include <fcntl.h>
#ifdef __linux__
# include <wait.h>
#endif

#define MAX_CONTENT 2046
#define MQ_FILE O_RDWR | O_TRUNC | O_CREAT
#define MQ_OFLAG S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
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

static void		change_nl2sp(char *c)
{
	*c = (*c == '\n') ? ' ' : *c;
}

static char		*get_file_content(void)
{
	int		fd;
	char	*a;
	int		byte;

	a = NULL;
	if (((fd = open(MQ_FILENAME, MQ_OFLAG)) == -1) ||
		(!(a = ft_memalloc(sizeof(char) * MAX_CONTENT + 1)) && close(fd) <= 0))
		return (a);
	if ((byte = read(fd, a, MAX_CONTENT)) > 0)
		a[byte - 1] = 0;
	ft_striter(a, &change_nl2sp);
	close(fd);
	return (a);
}

char			*process_magicquote(t_info *info, char *cmd)
{
	int			fdp[2];
	pid_t		pid;
	int			fd;

	pipe(fdp);
	if (!cmd || (fd = open(MQ_FILENAME, MQ_FILE, MQ_OFLAG)) == -1)
		return (NULL);
	if (!(pid = fork()))
	{
		dup2(fdp[1], 1);
		close(fdp[0]);
		ft_putendl(cmd);
		exit(0);
	}
	dup2(fdp[0], 0);
	close(fdp[1]);
	dup2(fd, 1);
	close(fd);
	wait(0);
	execution_motor(info, self_node(info), 1);
	return (get_file_content());
}

char			*apply_magicquote(t_info *info, char *str)
{
	t_word		*words;
	char		*tmp;
	char		*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if ((words = get_magicquotelist(str)))
	{
		treat_magicquote(info, words);
		tmp = make_sentence(words);
		tmp2 = ft_strtrim(tmp);
		ft_free_them_all(1, &tmp);
		free_list(words);
	}
	return (tmp2);
}
