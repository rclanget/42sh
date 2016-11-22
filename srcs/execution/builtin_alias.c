/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zipo <zipo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 15:56:22 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/22 22:16:54 by zipo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "alias_struct.h"
#include "shell.h"
#include "libft.h"

char	**split_alias(char *line)
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

static void	free_aliass(char **tmp)
{
	int		i;

	i = 0;
	while (tmp && tmp[i])
		free(tmp[i++]);
	if (tmp)
		free(tmp);
}

static void	show_aliases(t_info *info)
{
	t_alias	*alias;

	if ((alias = info->alias))
	{
		while (alias)
		{
			ft_print("%s=%s\n", alias->init, alias->replace);
			alias = alias->next;
		}
	}
}

int			builtin_alias(t_info *info, t_tree *cmd)
{
	char	**tmp;
	char	**val;

	tmp = cmd->cmd + 1;
	if (!tmp || !*tmp)
		show_aliases(info);
	while (tmp && *tmp)
	{
		if (!ft_strchr(*tmp, '='))
			break ;
		val = split_alias(*tmp);
		update_alias(info, val[0], val[1]);
		free_aliass(val);
		tmp++;
	}
	return (0);
}
