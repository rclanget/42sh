/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:35:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/10/23 20:58:10 by rclanget         ###   ########.fr       */
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
	static int	save[2];

	if (tosave)
	{
		save[0] = dup(0);
		save[1] = dup(1);
	}
	else
	{
		dup2(save[0], 0);
		close(save[0]);
		dup2(save[1], 1);
		close(save[1]);
	}
}

void			execution(t_info *info, t_tree *cmd, char **env)
{
	char	*tmp;

	if ((access(cmd->cmd[0], X_OK)) != -1)
		;
	else if ((tmp = executable_search(info, cmd->cmd[0])))
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
	int		status;
	char	**env;

	env = NULL;
	status = 0;
	if (!is_builtin(cmd->cmd[0]))
	{
		if ((pid = fork()) == -1)
			ft_exit_shell(info);
		if (!pid)
		{
			env = env_lst_tab(info->env);
			execution(info, cmd, env);
		}
		if (wait)
			waitpid(pid, &status, WUNTRACED);
		free_env_tab(env);
		return (execution_status(status));
	}
	return(execution_builtin(info, cmd));
}
