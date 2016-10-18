/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_dright.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 14:38:54 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 11:25:16 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"

#include <unistd.h>
#include <fcntl.h>

int				redirection_dright(t_info *info, t_tree *cmd)
{
	int		fd;
	int		ret;

	fd = -1;
	ret = 0;
	save_fd(1);
	if (cmd->right && cmd->right->cmd)
		fd = open(cmd->right->cmd[0], O_WRONLY | O_APPEND | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd != -1)
	{
		dup2(fd, 1);
		close(fd);
		ret = execution_motor(info, cmd->left, 1);
		save_fd(0);
		return (ret);
	}
	return (1);
}
