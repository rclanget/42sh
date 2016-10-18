/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 13:19:27 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 11:24:47 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"

#include <fcntl.h>
#include <unistd.h>

int			redirection_right(t_info *info, t_tree *cmd)
{
	int		fd;
	int		ret;

	fd = -1;
	ret = 0;
	save_fd(1);
	if (cmd->right && cmd->right->cmd)
		fd = open(cmd->right->cmd[0], O_WRONLY | O_TRUNC | O_CREAT,
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
