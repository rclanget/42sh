/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:01:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 00:10:05 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "alias_struct.h"
#include "var.h"

int			builtin_unset(t_info *info, t_tree *cmd)
{
	char	**tmp;

	if (!(tmp = cmd->cmd + 1))
	{
		ft_fdprint(2, "unset: not enough arguments");
		exit(1);
	}
	while (tmp && *tmp)
	{
		remove_var(info, *tmp);
		tmp++;
	}
	return (0);
}
