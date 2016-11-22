/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_builtin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 14:48:04 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/22 23:53:31 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "shell.h"
#include "libft.h"
#include "tools.h"

t_builtin	g_builtin[] =
{
	{"cd", &builtin_cd},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"env", &builtin_env},
	{"alias", &builtin_alias},
	{"echo", &builtin_echo},
	{"unalias", &builtin_unalias},
	{"history", &builtin_history},
	{"exit", &builtin_exit},
	{"true", &builtin_true},
	{"false", &builtin_false},
	{"read", &builtin_read},
	{"export", &builtin_export},
	{"unset", &builtin_unset}
};

int			is_builtin(char *cmd)
{
	int		i;

	i = -1;
	while (++i <= MAX_BUILTIN)
		if (!ft_strcmp(g_builtin[i].name, cmd))
			return (1);
	return (0);
}

int			execution_builtin(t_info *info, t_tree *cmd)
{
	int		i;

	i = -1;
	while (++i <= MAX_BUILTIN)
	{
		if (!ft_strcmp(g_builtin[i].name, cmd->cmd[0]))
			return (g_builtin[i].func(info, cmd));
	}
	return (0);
}
