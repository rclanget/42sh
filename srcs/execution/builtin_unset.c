/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulefebvr <ulefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:01:37 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 17:14:37 by ulefebvr         ###   ########.fr       */
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
		return (1);
	}
	while (tmp && *tmp)
	{
		remove_var(info, *tmp);
		tmp++;
	}
	return (0);
}
