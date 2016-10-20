/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 15:34:26 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 11:25:10 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"

#include <unistd.h>
#include <fcntl.h>

int			redirection_left(t_info *info, t_tree *cmd)
{
	int		fd;
	int		ret;

	fd = -1;
	ret = 0;
	save_fd(1);
	if (cmd->right)
		fd = open(cmd->right->elem, O_RDONLY);
	if (fd != -1)
	{
		dup2(fd, 0);
		close(fd);
		ret = execution_motor(info, cmd->left, 1);
		save_fd(0);
		return (ret);
	}
	return (1);
}
