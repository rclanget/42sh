/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 16:29:30 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/14 14:45:17 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#include <stdlib.h>
#include <unistd.h>

#ifdef __linux__
# include <wait.h>
#endif

int				operator_pipe2(t_info *info, t_tree *cmd)
{
	int			fdp[2];
	pid_t		pid;

	pipe(fdp);
	if (cmd->right && !(pid = fork()))
	{
		dup2(fdp[1], 1);
		close(fdp[0]);
		execution_motor(info, cmd->left, 0);
		exit(0);
	}
	dup2(fdp[0], 0);
	close(fdp[1]);
	wait(0);
	execution_motor(info, cmd->right, 1);
	return (0);
}

int				operator_pipe(t_info *info, t_tree *cmd)
{
	pid_t		pid;

	if (!(pid = fork()))
	{
		operator_pipe2(info, cmd);
		exit(0);
	}
	wait(0);
	return (0);
}
