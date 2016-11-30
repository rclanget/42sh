/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_unset_fn.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:01:03 by ulefebvr          #+#    #+#             */
/*   Updated: 2016/11/30 14:46:47 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "alias.h"
#include "alias_struct.h"

void		add_var(t_info *info, char *var, char *content)
{
	t_alias	*elem;
	t_alias	*tmp;

	elem = (t_alias *)ft_memalloc(sizeof(t_alias));
	elem->init = var;
	elem->replace = content;
	if ((tmp = info->var))
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	else
		info->var = elem;
}

void		remove_var(t_info *info, char *var)
{
	t_alias	*cpy;
	t_alias	*prev;
	t_alias	*tmp;

	prev = NULL;
	cpy = info->var;
	while (cpy && var)
	{
		if (!ft_strcmp(cpy->init, var))
		{
			tmp = cpy;
			cpy = cpy->next;
			if (prev)
				prev->next = cpy;
			else
				info->var = cpy;
			ft_free_them_all(3, &tmp->init, &tmp->replace, &tmp);
			break ;
		}
		prev = cpy;
		cpy = cpy->next;
	}
}

t_alias		*search_var(t_info *info, char *var)
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

void		update_var(t_info *info, char *init, char *replace)
{
	t_alias	*var;

	if (!(var = search_alias(info, init)))
		var = search_var(info, init);
	if (var)
	{
		free(var->replace);
		var->replace = ft_strdup(replace);
	}
	else
		add_var(info, ft_strdup(init), ft_strdup(replace));
}
