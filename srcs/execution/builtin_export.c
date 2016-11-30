/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:28:12 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/30 14:35:19 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "libft.h"
#include "alias_struct.h"
#include "var.h"

static char	**split_alias(char *line)
{
	char	**tab;
	char	*tmp;
	int		len;

	tab = (char **)malloc(sizeof(char *) * 3);
	tmp = ft_strchr(line, '=');
	tab[0] = ft_strsub(line, 0, tmp - line);
	len = ft_strlen(line) - (tmp - line);
	tab[1] = ft_strsub(line, tmp - line + 1, len - 1);
	tab[2] = 0;
	return (tab);
}

int			builtin_export(t_info *info, t_tree *cmd)
{
	char	**tmp;
	char	**val;

	tmp = cmd->cmd + 1;
	while (tmp && *tmp)
	{
		if (!ft_strchr(*tmp, '='))
			break ;
		val = split_alias(*tmp);
		update_var(info, val[0], val[1]);
		ft_free_them_all(3, &val[0], &val[1], &val);
		tmp++;
	}
	return (0);
}
