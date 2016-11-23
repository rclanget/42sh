/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 15:06:26 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:14:59 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "env.h"
#include "tools.h"
#include "libft.h"

int			builtin_unsetenv(t_info *info, t_tree *cmd)
{
	int		len;
	int		stat;
	char	**tmp;

	stat = 0;
	tmp = cmd->cmd;
	len = ft_tablen(cmd->cmd);
	if (len == 1 && ++stat)
		ft_fdprint(2, "unsetenv: Too few arguments.\n");
	else
	{
		while (++tmp && *tmp)
			env_remove_var(info, *tmp);
	}
	return (stat);
}
