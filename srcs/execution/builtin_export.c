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
#include "env.h"

t_alias		*search_alias_2(t_info *info, char *var)
{
	t_alias		*alias;

	alias = info->var;
	while (alias && var)
	{
		if (!ft_strcmp(alias->init, var))
			break ;
		alias = alias->next;
	}
	return (alias);
}

static void	show_localvar(t_info *info)
{
	t_env	*env;

	if ((env = info->env))
	{
		while (env)
		{
			ft_print("%s=%s\n", env->var, env->content);
			env = env->next;
		}
	}
}

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

void			builtin_export_2(t_info *info, char **tmp)
{
	t_alias	*un_alias;

	un_alias = NULL;
	if ((un_alias = search_alias_2(info, tmp[0])))
	{
		if (ft_isalpha(tmp[0][0]))
			env_update_var(info, tmp[0], un_alias->replace);
		else
			ft_fdprint(2, "export: '%s': identifier must begin with a letter\n", tmp[0]);
	}
}

int			builtin_export(t_info *info, t_tree *cmd)
{
	char	**tmp;
	char	**val;

	tmp = cmd->cmd + 1;
	if (!tmp || !*tmp)
		show_localvar(info);
	while (tmp && *tmp)
	{
		if (!ft_strchr(*tmp, '='))
		{
			builtin_export_2(info, tmp);
			break ;
		}
		val = split_alias(*tmp);
		if (ft_isalpha(val[0][0]))
			env_update_var(info, val[0], val[1]);
		else
			ft_fdprint(2, "export: '%s': identifier must begin with a letter\n", val[0]);
		ft_free_them_all(3, &val[0], &val[1], &val);
		tmp++;
	}
	return (0);
}
