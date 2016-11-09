/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:35:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/09 16:23:11 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "alias.h"
#include "tools.h"
#include "execution.h"
#include "builtin.h"
#include "env.h"

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void			save_fd(int tosave)
{
	static int	save[3];

	if (tosave)
	{
		save[0] = dup(0);
		save[1] = dup(1);
		save[2] = dup(2);
	}
	else
	{
		dup2(save[0], 0);
		close(save[0]);
		dup2(save[1], 1);
		close(save[1]);
		dup2(save[2], 2);
		close(save[2]);
	}
}

void			execution(t_info *info, t_tree *cmd, char **env)
{
	char	*tmp;

	if ((access(cmd->cmd[0], X_OK)) != -1)
		;
	else if ((tmp = lire_hashmap(info->hash, cmd->cmd[0])))
	{
		free(cmd->cmd[0]);
		cmd->cmd[0] = tmp;
	}
	else
	{
		ft_fdprint(2, "42sh: %s: command not found\n", cmd->cmd[0]);
		exit(1);
	}
	execve(cmd->cmd[0], cmd->cmd, env);
}

int				execution_command(t_info *info, t_tree *cmd, int wait)
{
	pid_t	pid;
	char	**env;

	env = NULL;
	if (!is_builtin(cmd->cmd[0]) && ((access(cmd->cmd[0], X_OK)) != -1 ||
		lire_hashmap(info->hash, cmd->cmd[0])))
	{
		if ((pid = fork()) == -1)
			exit_shell(info);
		else if (!pid && !ft_signal(1))
			execution(info, cmd, env = env_lst_tab(info->env));
		if (wait)
			waitpid(pid, &info->status, WUNTRACED);
		free_env_tab(env);
		return (execution_status(info->status));
	}
	else if (is_builtin(cmd->cmd[0]))
		return(execution_builtin(info, cmd));
	ft_fdprint(2, "42sh: %s: command not found\n", cmd->cmd[0]);
	return (execution_status(info->status = 127));
}
