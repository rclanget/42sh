/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 13:19:27 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/20 16:45:48 by gdeguign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "operator.h"
#include "libft.h"

#include <fcntl.h>
#include <unistd.h>

int			redirection_right(t_info *info, t_tree *cmd)
{
	int		fd;
	int		ret;

	fd = -1;
	ret = 0;
	save_fd(1);
	if (cmd->right)
		fd = redirection_get_fd(cmd);
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
