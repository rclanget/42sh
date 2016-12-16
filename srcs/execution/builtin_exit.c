/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:28:36 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/12/16 12:10:15 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "tools.h"

#include <sys/wait.h>

int			is_number(char *str)
{
	int		ret;

	--str;
	while (++str && *str)
		if (!(ret = ft_isdigit(*str)))
			break ;
	return (ret);
}

int			builtin_exit(t_info *info, t_tree *cmd)
{
	if (1 == ft_tablen(cmd->cmd + 1))
	{
		if (is_number(cmd->cmd[1]))
			info->status = W_EXITCODE(ft_atoi(cmd->cmd[1]), 0);
		else
		{
			ft_fdprint(2, "42sh: Exit: %s: numeric argument required\n",
				cmd->cmd[1]);
			info->status = W_EXITCODE(255, 1);
		}
		info->stop = 1;
	}
	else if (2 == ft_tablen(cmd->cmd + 1))
	{
		info->status = 1;
		ft_fdprint(2, "42sh: Exit: too many arguments\n");
	}
	else
		info->stop = 1;
	return (info->status);
}
