/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 14:39:06 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:26:17 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "env.h"
#include "tools.h"
#include "libft.h"

#include <stdlib.h>

int			builtin_setenv(t_info *info, t_tree *cmd)
{
	int		len;
	int		stat;
	t_env	*tmp;

	stat = 1;
	tmp = info->env;
	len = ft_tablen(cmd->cmd);
	if (len == 1)
		while (len == 1 && tmp)
		{
			ft_print("%s=%s\n", tmp->var, tmp->content);
			tmp = tmp->next;
		}
	else if (len <= 3)
		env_update_var(info, cmd->cmd[1], cmd->cmd[2]);
	else
	{
		ft_fdprint(2, "setenv: Too many arguments.\n");
		stat = 0;
	}
	return (stat);
}
