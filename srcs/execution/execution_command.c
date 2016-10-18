/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 16:35:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/03/04 15:14:31 by ulefebvr         ###   ########.fr       */
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

char			**execution_alias(t_info *info, char **cmd_o)
{
	char	*tmp;
	char	**tab;
	char	**cmd;

	if (cmd_o && (tmp = check_alias(info, cmd_o[0])))
	{
		tab = ft_strsplit(tmp, ' ');
		cmd = ft_tabjoin(tab, &cmd_o[1]);
		free(tab);
		free(cmd_o[0]);
		free(cmd_o);
		free(tmp);
	}
	else
		cmd = cmd_o;
	return (cmd);
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
	cmd->cmd = execution_alias(info, cmd->cmd);
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
