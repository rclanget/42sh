/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unalias.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 17:01:19 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/02/29 10:22:37 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "alias.h"
#include "libft.h"

int			builtin_unalias(t_info *info, t_tree *cmd)
{
	char	**tmp;

	if (!(tmp = cmd->cmd + 1))
	{
		ft_fdprint(2, "unalias: not enough arguments");
		exit(1);
	}
	while (tmp && *tmp)
	{
		remove_alias(info, *tmp);
		tmp++;
	}
	return (0);
}
