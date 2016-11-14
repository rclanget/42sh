/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_get_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 13:19:27 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 14:48:20 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "libft.h"
#include "error.h"
#include "execution.h"
#include "tools.h"
#include "hashmap.h"

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define IS_REDIR(x) (x == 5 || x == 6 || x == 7 || x == 8)
#define TO_LEFT(x) (x == 6 || x == 8)
#define IN 0
#define OUT 1
#define GET_FILE(x) (x->type ? x->left->elem : x->elem)

#define RIGHT(x) (x == 5)
#define DRIGHT(x) (x == 7)
#define LEFT(x) (x == 6)

#define FILE_RIGHTS S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH

int			get_the_flags(int type)
{
	int		oflags;

	if (LEFT(type))
		oflags = O_RDONLY;
	else
		oflags = O_WRONLY | (RIGHT(type) ? O_TRUNC : O_APPEND) | O_CREAT;
	return (oflags);
}

int			replace_actual_file(int fd, char *filename, int type)
{
	int		new_fd;

	close(fd);
	if (LEFT(type))
		new_fd = open(filename, get_the_flags(type));
	else
		new_fd = open(filename, get_the_flags(type), FILE_RIGHTS);
	dup2(new_fd, LEFT(type) ? 0 : 1);
	close(new_fd);
	return (new_fd);
}

char		*get_filename(t_tree *cmd)
{
	if (cmd->type)
	{
		cmd->left->cmd = cust_split(cmd->left->elem);
		return (cmd->left->cmd[0]);
	}
	else
	{
		cmd->cmd = cust_split(cmd->elem);
		return (cmd->cmd[0]);
	}
}

char		*treat_agreg(t_tree *cmd)
{
	if (cmd->type)
	{
		free_tab(cmd->left->cmd);
		cmd->left->cmd = redirection_agreg(cust_split(cmd->left->elem));
		return (cmd->left->elem);
	}
	else
	{
		free_tab(cmd->cmd);
		cmd->cmd = redirection_agreg(cust_split(cmd->elem));
		return (cmd->elem);
	}
}

int			redirection_get_fd(t_tree *cmd, int *fds)
{
	ft_bzero(fds, sizeof(int) * 2);
	fds[0] = -1;
	fds[1] = -1;
	while (cmd->right && cmd->type)
	{
		fds[!(TO_LEFT(cmd->type)) ? 1 : 0] = replace_actual_file(
			fds[!(TO_LEFT(cmd->type)) ? 1 : 0],
			get_filename(cmd->right),
			cmd->type);
		treat_agreg(cmd->right);
		if (fds[!(TO_LEFT(cmd->type)) ? 1 : 0] == -1)
		{
			ft_fdprint(2, "42sh: %s: %s\n", ft_strerror(errno),
				get_filename(cmd->right));
			close(fds[!(TO_LEFT(cmd->type)) ? 0 : 1]);
			fds[!(TO_LEFT(cmd->type)) ? 0 : 1] = -1;
		}
		cmd = cmd->right;
	}
	return (0);
}
