/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_all.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 15:31:07 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/06 18:52:03 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "libft.h"
#include "execution.h"

#include <fcntl.h>
#include <unistd.h>

int			redirection_all(t_info *info, t_tree *cmd)
{
	int		fds[2];
	int		ret;

	ret = 1;
	save_fd(1);
	if (cmd->right)
	{
		apply_fd_agreg(cmd);
		redirection_get_fd(cmd, fds);
	}
	if (fds[0] != -1 || fds[1] != -1)
	{
		if (fds[0] != -1)
		{
			dup2(fds[0], 0);
			close(fds[0]);
		}
		if (fds[1] != -1)
		{
			dup2(fds[1], 1);
			close(fds[1]);
		}
		ret = execution_motor(info, cmd->left, 1);
	}
	save_fd(0);
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
