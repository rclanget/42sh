/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 16:29:30 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/04 15:06:56 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

#include <stdlib.h>
#include <unistd.h>

int                operator_pipe(t_info *info, t_tree *cmd)
{
	int			fdp[2];
	pid_t		pid;

	pipe(fdp);
	if (cmd->right && !(pid = fork()))
	{
		dup2(fdp[0], 0);
		close(fdp[0]);
		close(fdp[1]);
		execution_motor(info, cmd->right, 0);
		exit(0);
	}
	dup2(fdp[1], 1);
	close(fdp[1]);
	close(fdp[0]);
	execution_motor(info, cmd->left, 1);
	return (0);
}
