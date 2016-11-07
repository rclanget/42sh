/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:31:07 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/06 22:34:42 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "libft.h"
#include "execution.h"
#include "tools.h"

#include <fcntl.h>
#include <unistd.h>

int			redirection_all(t_info *info, t_tree *cmd)
{
	int		fds[2];
	int		ret;

	ret = 1;
	if (cmd->left)
		cmd->left->cmd = redirection_agreg(cust_split(cmd->left->elem));
	if (cmd->right)
		redirection_get_fd(cmd, fds);
	if (fds[0] != -1 || fds[1] != -1)
		ret = execution_command(info, cmd->left, 1);
	return (ret);
}

int			redirection_right(t_info *info, t_tree *cmd)
{
	return (redirection_all(info, cmd));
}

int			redirection_dright(t_info *info, t_tree *cmd)
{
	return (redirection_all(info, cmd));
}

int			redirection_left(t_info *info, t_tree *cmd)
{
	return (redirection_all(info, cmd));
}

int			redirection_dleft(t_info *info, t_tree *cmd)
{
	return (redirection_all(info, cmd));
}
